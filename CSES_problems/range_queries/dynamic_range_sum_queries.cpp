#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
vector<int> seg(4 * maxn);

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p] = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void update(int p, int l, int r, int u, int k){
    if(l == r){
        seg[p] = k;
    }else{

        int mid = (l + r) / 2;
        if(u <= mid) update(p * 2, l, mid, u, k);
        else update(p * 2 + 1, mid + 1, r, u, k);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid, L, R);
    int qr = query(p * 2 + 1, mid + 1, r, L, R);

    return ql + qr;
}

void solve() {
    int n, q; cin >> n >> q;
    
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);
    while(q--){
        int x; cin >> x;

        if(x == 1){
            int k, u; cin >> k >> u;
            k--;
            update(1, 0, n - 1, k, u);
        }

        if(x == 2){
            int l, r; cin >> l >> r;
            l--;
            r--;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

