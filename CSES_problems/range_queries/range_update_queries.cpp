#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
int seg[maxn * 4], lazy[maxn * 4];

void build(int p, int l, int r, vector<int> &a){
    if(l == r) seg[p] = a[l];
    else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, a);
        build(p * 2 + 1, mid + 1, r, a);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void push(int p, int l, int r){
    if(lazy[p] != 0){
        seg[p] += lazy[p] * (r - l + 1);

        if(r != l){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
    }

    lazy[p] = 0;
}

void update(int p, int l, int r, int L, int R, int v){
    push(p, l, r);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[p] = v;
        push(p, l, r);
    }else{
        int mid = (l + r) / 2;
        update(p * 2, l, mid, L, R, v);
        update(p * 2 + 1, mid + 1, r, L, R, v);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l , int r, int i){
    push(p, l, r);
    if(l > i || r < i) return 0;
    if(l == i && r == i) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid, i);
    int qr = query(p * 2 + 1, mid + 1, r, i);
    return qr + ql;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);

    while(q--){
        int a; cin >> a;

        if(a == 1){
            int l, r, v; cin >> l >> r >> v;
            l--;
            r--;
            update(1, 0, n - 1, l, r, v);
            
        }

        if(a == 2){
            int k; cin >> k;
            k--;
            cout << query(1, 0, n - 1, k) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

