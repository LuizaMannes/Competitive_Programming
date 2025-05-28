#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx];

void bfs(int s, vector<int> &dist){
    dist[s] = 0;

    queue<int> q;
    q.emplace(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
    bfs(1, dist1);

    int mxd = 0, s = 0;
    for(int i = 1; i <= n; i++){
        if(dist1[i] >= mxd){
            mxd = dist1[i];
            s = i;
        }

        dist1[i] = -1;
    }

    bfs(s, dist1);

    mxd = 0, s = 0;
    for(int i = 1; i <= n; i++){
        if(dist1[i] >= mxd){
            mxd = dist1[i];
            s = i;
        }
    }

    bfs(s, dist2);

    for(int i = 1; i <= n; i++){
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

