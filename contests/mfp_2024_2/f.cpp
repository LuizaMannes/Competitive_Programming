#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using pii = pair<int, int>;

const int mx = 2e5 + 5;
vector<pii> adj[mx];
int vis[mx];

bool dfs(int u, int t, int mid){
    vis[u] = 1;
    if(u == t) return true;

    for(auto [v, c] : adj[u]){
        if(!vis[v] && c >= mid) 
            if(dfs(v, t, mid)) return true;
    }

    return false;
}

void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int l = 0, r = 1e9 + 9, res = -1;
    while(l <= r){
        for(int i = 1; i <= n; i++) vis[i] = 0;
        int mid = (l + r) / 2;
        
        if(dfs(s, t, mid)){
            res = mid;
            l = mid + 1;
        }else r = mid - 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

