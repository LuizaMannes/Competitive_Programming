#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 3e5 + 5;
vector<pair<int,int>> adj[mx];
int tin[mx], low[mx], vn[mx], ve[mx], t = 0;
bool ok = 1;

void dfs_bridge(int u, int p = -1){
    low[u] = tin[u] = ++t;
    for(auto [v, id]: adj[u]){
        if(id == p) continue;
        if(tin[v] != 0){
            low[u] = min(low[u], tin[v]);
        }else{
            dfs_bridge(v, id);
            low[u] = min(low[u], low[v]);
        }
    }

    if(p != -1 && low[u] == tin[u]){
        ok = 0;
    }
}

void res(int u, int p = -1){
    vn[u] = 1;

    for(auto [v, id]: adj[u]){
        if(ve[id]) continue;
        cout << u << " " << v << endl;
        ve[id] = 1;
        if(vn[v]) continue;
        res(v, id);
    }
}


void solve() {
    int n, m; cin >> n >> m;

    int id = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, id});
        adj[b].push_back({a, id});
        id++;
    }
    
    dfs_bridge(1);
    for(int i = 1; i <= n; i++) if(tin[i] == 0) ok = 0;
    if(!ok){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    res(1);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

