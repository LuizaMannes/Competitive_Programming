#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 3e5 + 5;

vector<int> adj[mx], nadj[mx];
int t = 0, tin[mx], low[mx], comp[mx], vis[mx];
map<pair<int,int>,int> bridge;

void dfs_bridge(int u, int p = -1) {
    low[u] = tin[u] = ++t;
    for (int v : adj[u]) {
        if (tin[v] != 0 && v != p) {
            low[u] = min(low[u], tin[v]);
        } else if (v != p) {
            dfs_bridge(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (p != -1 && low[u] == tin[u]) {
        bridge[pair<int,int> (p, u)] = 1;
        bridge[pair<int,int> (u, p)] = 1;
    }
}

void dfs_comp(int u, int c){
    vis[u] = 1;
    comp[u] = c;

    for(int v: adj[u]){
        if(vis[v] || bridge[pair<int,int>(u,v)]) continue;
        dfs_comp(v, c);
    }
}

vector<int> bfs(int s){
    vector<int> dist(mx, -1);
    dist[s] = 0;
    queue<int> q;
    q.emplace(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: nadj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }

    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs_bridge(1);

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs_comp(i, ++c);
    }

    for(int i = 1; i <= n; i++){
        for(int u: adj[i]){
            if(comp[u] != comp[i]) {
                nadj[comp[i]].push_back(comp[u]);
                nadj[comp[u]].push_back(comp[i]);
            }
        }
    }

    vector<int> dist1 = bfs(1);

    int mdist = 0, s = 0;
    for(int i = 1; i <= c; i++){
        if(dist1[i] > mdist){
            mdist = dist1[i];
            s = i;
        }
    }

    vector<int> dist2 = bfs(s);
    mdist = 0;
    for(int i = 1; i <= c; i++){
        mdist = max(mdist, dist2[i]);
    }
    cout << mdist << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

