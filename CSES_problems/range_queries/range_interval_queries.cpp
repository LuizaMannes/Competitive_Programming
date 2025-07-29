#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
const int mx = 2e5 + 5;
 
vector<int> seg, Lc, Rc, roots;
 
int newnode(){
    seg.push_back(0);
    Lc.push_back(0);
    Rc.push_back(0);
    return seg.size() - 1;
}
 
int lc(int p, bool c = false){
    if(c && Lc[p] == 0) Lc[p] = newnode();
    return Lc[p];
}
 
int rc(int p, bool c = false){
    if(c && Rc[p] == 0) Rc[p] = newnode();
    return Rc[p];
}
 
int query(int p, int p2, int l, int r, int L, int R){
    if(p == 0 || l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p] - seg[p2];
 
    int mid = (l + r) / 2;
    int ql = query(lc(p), lc(p2), l, mid, L, R);
    int qr = query(rc(p), rc(p2), mid + 1, r, L, R);
 
    return ql + qr;
}
 
void update(int p, int old, int l, int r, int i){
    seg[p] = seg[old];
    if(l == r) seg[p] += 1;
    else{
        int mid = (l + r) / 2;
 
        if(i <= mid){
            Rc[p] = rc(old);
            update(lc(p, true), lc(old), l, mid, i);
        }else{
            Lc[p] = lc(old);
            update(rc(p,true), rc(old), mid + 1, r, i);
        }
 
        seg[p] = seg[lc(p)] + seg[rc(p)];
    }
}

void solve() {
    int n, q; cin >> n >> q;

    seg.reserve(mx); Lc.reserve(mx); Rc.reserve(mx); roots.reserve(mx);
    roots.push_back(newnode());

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    vector<int> sortar = ar;

    sort(sortar.begin(), sortar.end());
    sortar.erase(unique(sortar.begin(), sortar.end()), sortar.end());

    for(int i = 0; i < n; i++){
        int ind = upper_bound(sortar.begin(), sortar.end(), ar[i]) - sortar.begin();

        int new_root = newnode();
        update(new_root, roots.back(), 1, mx, ind);
        roots.push_back(new_root);
    }

    while(q--){
        int l, r, a, b; cin >> l >> r >> a >> b;
        l--;
        int inda = lower_bound(sortar.begin(), sortar.end(), a) - sortar.begin() + 1;
        int indb;
        if(a != b) indb = upper_bound(sortar.begin(), sortar.end(), b) - sortar.begin();
        else indb = inda;

        //cout << inda << " " << indb << endl;

        cout << query(roots[r], roots[l], 1, mx, inda, indb) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

