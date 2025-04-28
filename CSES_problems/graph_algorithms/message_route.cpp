#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn=1e5+10;

vector<int> adj[maxn];
vector<int> pais(maxn,-1);
int n;
vector<int> dist(maxn, -1);

void bfs(int s) {
    queue<int> q;
    dist[s] = 1;
    q.emplace(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                pais[v]=u;
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
}

void res(int a){
    vector<int> path;
    int nodo=a;
    path.push_back(a);
    while(pais[nodo]!=-1){
        path.push_back(pais[nodo]);
        nodo=pais[nodo];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
        cout << path[i] << " \n" [i==path.size()-1];
    }
}


void solve() {
    int m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    if(dist[n]==-1) cout << "IMPOSSIBLE" << endl;
    else{
        cout << dist[n] << endl;
        res(n);
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

