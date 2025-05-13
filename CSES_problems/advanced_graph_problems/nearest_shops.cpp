#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = tuple<int,int,int>;

const int mx = 2e5 + 5;
vector<int> adj[mx], aux(mx);
int dist[mx][2];
queue<T> q;

void bfs(){
    while(q.size()){
        auto[u, x, id] = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(dist[v][0] == -1){
                aux[u] = id;
                dist[v][0] = dist[u][x] + 1;
                q.emplace(v, 0, id);
            }else if(dist[v][1] == -1 && id != aux[v]){
               if(id == v){
                   q.emplace(v, 1, id);
                   continue;
               }
               dist[v][1] = dist[u][x] + 1;
               q.emplace(v, 1, id);
            }
        }
    }     
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    for(int i = 0; i <= n; i++){
        dist[i][0] = -1;
        dist[i][1] = -1;
    }
    
    map<int,int> ma;
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        ma[a] = 1;
        q.emplace(a, 0, a);
        dist[a][0] = 0;
    }

    for(int i = 0; i <  m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bfs();

    for(int i = 1; i <= n; i++){
        if(ma[i]) cout << dist[i][1] << " ";
        else cout << dist[i][0] << " ";
    }

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

