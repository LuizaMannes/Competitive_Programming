#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MAX = 12e5 + 5;
const int maxn = 2e5 + 5;
vector<int> seg, Lc, Rc, roots;

void reserve(){
    seg.reserve(MAX); Lc.reserve(MAX); Rc.reserve(MAX); roots.reserve(maxn);
}

int newnode(){
    seg.push_back(0);
    Lc.push_back(-1);
    Rc.push_back(-1);

    return seg.size() - 1;
}

int lc(int p){
    if(Lc[p] == -1) Lc[p] = newnode();
    return Lc[p];
}

int rc(int p){
    if(Rc[p] == -1) Rc[p] = newnode();
    return Rc[p];
}

void build(int p, int l, int r, vector<int> &ar){
    if(l == r) seg[p] = ar[l];
    else{
        int mid = (l + r) / 2;
        build(lc(p), l, mid, ar);
        build(rc(p), mid + 1, r, ar);

        seg[p] = seg[lc(p)] + seg[rc(p)];
    }
}

void copy(int k){
    int new_root = newnode();
    seg[new_root] = seg[roots[k]];
    Lc[new_root] = Lc[roots[k]];
    Rc[new_root] = Rc[roots[k]];

    roots.push_back(new_root);
}

int query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];
    
    int mid = (l + r) / 2;
    int ql = query(lc(p), l, mid, L, R);
    int qr = query(rc(p), mid + 1, r, L, R);

    return ql + qr;
}

void update(int p, int old, int l, int r, int i, int x){
    if(l == r){
        seg[p] = x;
    }else{
        int mid = (l + r) / 2;

        if(i <= mid){
            Rc[p] = rc(old);
            int temp = newnode();
            update(temp, lc(old), l, mid, i, x); 
            Lc[p] = temp;
        }else{
            Lc[p] = lc(old);
            int temp = newnode();
            update(temp, rc(old), mid + 1, r, i, x);
            Rc[p] = temp;
        }

        seg[p] = seg[lc(p)] + seg[rc(p)];
    }
}

void solve() {
    int n, q; cin >> n >> q;

    reserve();
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    roots.push_back(newnode());
    build(0, 0, n - 1, ar);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int k, a, x; cin >> k >> a >> x;
            k--; a--;
            update(roots[k], roots[k], 0, n - 1, a, x);
        }else if(t == 2){
            int k, a, b; cin >> k >> a >> b; 
            k--; a--; b--;
            cout << query(roots[k], 0, n - 1, a, b) << endl;  
        }else{
            int k; cin >> k;
            k--;
            copy(k);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

