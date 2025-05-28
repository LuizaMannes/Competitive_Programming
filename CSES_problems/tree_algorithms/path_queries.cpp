#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx], tin(mx), tout(mx), seg(4 * mx);
int T = 0;

void dfs(int u, int p){
    tin[u] = T++;

    for(auto v: adj[u]){
        if(v != p) dfs(v, u);
    }

    tout[u] = T;
}

void update(int p, int l, int r, int i, int x){
    if(l == r) seg[p] += x;
    else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, x);
        else update(p * 2 + 1, mid + 1, r, i, x);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];
    else{
        int mid = (l + r) / 2;
        int ql = query(p * 2, l, mid, L, R);
        int qr = query(p * 2 + 1, mid + 1, r, L, R);

        return ql + qr;
    }
}
    
void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 1; i <= n; i++) cin >> ar[i]; 

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        update(1, 0, n, tin[i], ar[i]);
        update(1, 0, n, tout[i], -ar[i]);
    }

    while(q--){
        int t, s; cin >> t >> s;
        if(t == 1){
            int x; cin >> x;
            update(1, 0, n, tin[s], x - ar[s]);
            update(1, 0, n, tout[s], -(x - ar[s]));
            ar[s] = x;
        }else{
            cout << query(1, 0, n, tin[1], tin[s]) << endl; 
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

