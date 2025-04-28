#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5+5;
const int INF = 1e9;

vector<int> adj[mx], radj[mx], radj2[mx], dist(mx, INF), topo;
int ciclos[mx], vis[mx], vis2[mx];
queue<int> q;

void tp(int u){
    vis[u]++;
    
    for(auto v: adj[u]){
        if(!vis[v]) tp(v);
    }

    topo.push_back(u);
}

int dfs(int u, int c, int t){
    vis2[u]++;
    ciclos[u] = c;

    for(auto v: radj[u]){
        if(!vis2[v]) return dfs(v, c, t+1);
    }

    return t;
}

void bfs(){
    
    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(auto v: radj2[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;

                q.emplace(v);
            }
        }
    }
}

void solve() {
    int n; cin >> n;

    vector<int> res(n+1);

    for(int i = 1; i <= n; i++){
        int a; cin >> a;

        if(a == i) dist[i] = 1;
        
        adj[i].push_back(a);
        radj[a].push_back(i);
    }

    for(int i = 1; i <= n; i++) if(!vis[i]) tp(i);

    reverse(topo.begin(),topo.end());
    
    for(auto i: topo){
        if(!vis2[i]){
            int t = dfs(i, i, 1);
            if(t > 1 || dist[i] == 1){
                if(dist[i] == INF) dist[ciclos[i]] = t;
                q.emplace(ciclos[i]);
            }
        }
    }

    for(int u = 1; u <= n; u++){
        for(auto v: radj[u]){
            if(ciclos[u] == ciclos[v]) continue;

            radj2[ciclos[u]].push_back(ciclos[v]);
        }
    }
    bfs();

    for(int i = 1; i <= n; i++){
        cout << dist[ciclos[i]] << ' ';
    }

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

