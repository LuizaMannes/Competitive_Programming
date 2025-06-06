#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MAX = 12e5 + 5;
const int maxn = 1e5 + 5;

struct node{
    int suf, pref, m;
};

vector<node> seg;
vector<int> Lc, Rc, roots;

void reserve(){
    seg.reserve(MAX); Lc.reserve(MAX); Rc.reserve(MAX); roots.reserve(maxn);
}

int newnode(){
    node neutro;
    neutro.suf = neutro.pref = neutro.m = 0;
    seg.push_back(neutro);
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

void build(int p, int l, int r){
    if(l == r) seg[p].suf = seg[p].pref = seg[p].m = 0;
    else{
        int mid = (l + r) / 2;
        build(lc(p), l, mid);
        build(rc(p), mid + 1, r);
 
        seg[p].suf = seg[p].pref = seg[p].m = 0;
    }
}
 
void update(int p, int old, int l, int r, int i){
     if(l == r){
        seg[p].suf = seg[p].pref = seg[p].m = 1;
     }else{
        int mid = (l + r) / 2;
 
        if(i <= mid){
            Rc[p] = rc(old);
            update(lc(p), lc(old), l, mid, i); 
        }else{
            Lc[p] = lc(old);
            update(rc(p), rc(old), mid + 1, r, i);
        }

        if(seg[lc(p)].pref == (mid - l + 1)){
            seg[p].pref = seg[rc(p)].pref + seg[lc(p)].pref;
        }else seg[p].pref = seg[lc(p)].pref;

        if(seg[rc(p)].suf == (r - (mid + 1) + 1)){
            seg[p].suf = seg[rc(p)].suf + seg[lc(p)].suf;
        }else seg[p].suf = seg[rc(p)].suf;

        seg[p].m = max(seg[lc(p)].m, seg[rc(p)].m);
        seg[p].m = max(seg[p].m, seg[lc(p)].suf + seg[rc(p)].pref);
     }
}

node query(int p, int l, int r, int L, int R){
    if(l > R || r < L) {
        node neutro;
        neutro.suf = neutro.pref = neutro.m = 0;
        return neutro;
    }
    if(l >= L && r <= R) return seg[p];
    
    
    int mid = (l + r) / 2;
    node ql = query(lc(p), l, mid, L, R);
    node qr = query(rc(p), mid + 1, r, L, R); 
    
    node res;
    if(ql.pref == (mid - l + 1)){
        res.pref = qr.pref + ql.pref;
    }else res.pref = ql.pref;

    if(qr.suf == (r - (mid + 1) + 1)){
        res.suf = qr.suf + ql.suf;
    }else res.suf = qr.suf;

    res.m = max(ql.m, qr.m);
    res.m = max(res.m, ql.suf + qr.pref);
    return res;
}

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    vector<pair<int,int>> in;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        in.push_back({ar[i], i});
    }

    roots.push_back(newnode());
    build(roots[0], 0, n - 1);

    sort(in.rbegin(),in.rend());
    for(auto [a, i] : in){
        int new_root = newnode();
        int old = roots.back();
        update(new_root, old, 0, n - 1, i);
        roots.push_back(new_root);
    }

    sort(ar.rbegin(), ar.rend());

    int m; cin >> m;
    while(m--){
        int a, b, w; cin >> a >> b >> w;
        a--; b--;

        int l = 0, r = n - 1, res = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            node q = query(roots[mid + 1], 0, n - 1, a, b);

            if(q.m >= w){
                r = mid - 1;
                res = ar[mid];
            }else l = mid + 1;
        }
        cout << res << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

