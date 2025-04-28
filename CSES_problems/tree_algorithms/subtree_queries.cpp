#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx], v(mx), tin(mx), tout(mx), ar(mx), seg(4 * mx);
int T = 0;

void dfs(int u, int p){
    T++;

    tin[u] = T;
    ar[T] = u;
    for(auto v: adj[u]){
        if(v != p) dfs(v, u);
    }

    tout[u] = T;
}

void build(int p, int l, int r){
    if(l == r){
        seg[p] = v[ar[l]];
    } else {
        int mid = (l + r) / 2;

        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void update(int p, int l, int r, int i, int x){
    if(l == r){
        seg[p] = x;
    } else {
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, x);
        else update(p * 2 + 1, mid + 1, r, i, x);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int L, int r, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, L, mid, R);
    int qr = query(p * 2 + 1, mid  + 1, L, r, R);

    return ql + qr;
}

void solve() {
    int n, q; cin >> n >> q;
    
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    
    build(1, 0, n);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int a, b; cin >> a >> b;
            update(1, 0, n, tin[a], b);
        }

        if(t == 2){
            int a; cin >> a;
            cout << query(1, 0, tin[a], n, tout[a]) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

