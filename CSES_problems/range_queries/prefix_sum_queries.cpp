#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Node{
    int s, pref;
} seg[4 * maxn];

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p].s = seg[p].pref = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);

        seg[p].s = seg[p * 2].s + seg[p * 2 + 1].s;
        seg[p].pref = max(seg[p * 2].pref, seg[p * 2].s + seg[p * 2 + 1].pref);
    }
}

void update(int p, int l, int r, int i, int k){
    if(l == r){
        seg[p].s = seg[p].pref = k;
    }else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, k);
        else update(p * 2 + 1, mid + 1, r, i, k);

        seg[p].s = seg[p * 2].s + seg[p * 2 + 1].s;
        seg[p].pref = max(seg[p * 2].pref, seg[p * 2].s + seg[p * 2 + 1].pref);
    }
}

Node query(int p, int l, int r, int L, int R){
    if(l > R || r < L){
        Node temp;
        temp.s = temp.pref = 0;
        return temp;
    }
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    Node ql = query(p * 2, l, mid, L, R);
    Node qr = query(p * 2 + 1, mid + 1, r, L, R);
    
    Node n;
    n.s = ql.s + qr.s;
    n.pref = max(ql.pref, ql.s + qr.pref);
    return n;
}

int res(int L, int R, int s){
    Node n = query(1, 0, s, L, R);

    return n.pref;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);

    while(q--){
        int a; cin >> a;
        if(a == 1){
            int i, k; cin >> i >> k;
            i--;
            update(1, 0, n - 1, i, k);
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << max(0ll, res(l, r, n - 1)) << endl;
        } 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

