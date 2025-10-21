#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 4e5 + 5;

vector<pair<int,int>> adj[mx], edges(mx);
int tin[mx], low[mx], comp[mx], sz[mx], vis[mx], t = 0;
map<pair<int,int>, int> bridges;

void dfs_bridge(int u, int p = -1) {
    low[u] = tin[u] = ++t;
    for (auto [v, i] : adj[u]) {
        if (tin[v] != 0 && v != p) {
            low[u] = min(low[u], tin[v]);
        } else if (v != p) {
            dfs_bridge(v, u);
            low[u] = min(low[u], low[v]);
        }
    }

    if (p != -1 && low[u] == tin[u]) {
        bridges[pair<int,int>(p, u)] = 1;
        bridges[pair<int,int>(u, p)] = 1;
    }
}

void dfs_comp(int u, int c){
    vis[u] = 1;
    comp[u] = c;
    sz[c]++;
    for(auto [v, i]: adj[u]){
        if(vis[v] || bridges[pair<int,int>(u,v)]) continue;
        dfs_comp(v,c);
    }
}

void dfs(int u){
    vis[u] = 1;

    for(auto [v, i]: adj[u]){
        if(edges[i].first == 0){
            if(bridges[pair<int,int>(u,v)]){
                edges[i] = {v, u};
            }else edges[i] = {u, v};
        }
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    dfs_bridge(1);

    int c = 0, res = 0, s = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs_comp(i, ++c);
        if(sz[comp[i]] > res){
            res = sz[comp[i]];
            s = i;
        }
    }

    memset(vis, 0, sizeof(vis));
    dfs(s);

    cout << res << endl;
    for(int i = 0; i < m; i++){
        cout << edges[i].first << " " << edges[i].second << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

