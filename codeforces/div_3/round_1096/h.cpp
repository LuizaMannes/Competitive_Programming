#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
vector<int> adj[mx];

vector<int> bfs(int s){
    vector<int> dist(mx, -1);
    dist[s] = 0;
    queue<int> q;
    q.emplace(s);

    while(q.size()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.emplace(v);
            }
        }
    }

    return dist;
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> d1 = bfs(1);
    int s = 0, m = 0;
    for(int i = 1; i <= n; i++){
        if(d1[i] > m){
            m = d1[i];
            s = i;
        }
    }

    vector<int> d2 = bfs(s);
    s = 0, m = 0;
    for(int i = 1; i <= n; i++){
        if(d2[i] > m){
            m = d2[i];
            s = i;
        }
    }
    
    cout << m + (n - 1) - m - 1 << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

