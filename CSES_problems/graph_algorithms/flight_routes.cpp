#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = tuple<int,int,int>;

const int mx = 1e5+5;
const int INF = 1e18;

vector<pair<int,int>> adj[mx];

vector<vector<int>> dij(int s, int k){
    vector<vector<int>> dist(mx,vector<int> (k+1));
    for(int i = 0; i < mx; i++){
        for(int j = 1; j <= k; j++){
            dist[i][j] = INF;
        }
    }

    dist[s][1] = 0;
    
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(dist[s][1], s, 1);
    while(!pq.empty()){
        auto [d, u, in] = pq.top();
        pq.pop();
        
        bool ok = false;
        for(int i = 1; i <= k; i++) if(dist[u][i] >= d) ok = true;

        if(!ok || in > k) continue;

        for(auto [w ,v]: adj[u]){
            int ind = 0;
            int maior = 0;
            
            for(int i = 1; i <= k; i++){
                if(dist[v][i] >= maior){
                    maior = dist[v][i];
                    ind = i;
                }
            }

            if(dist[v][ind] > d + w){
                dist[v][ind] = d + w;
                pq.emplace(dist[v][ind], v, ind);
            }
        }
    }

    return dist;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(c,b);
    }

    vector<vector<int>> dist = dij(1, k);
    
    sort(dist[n].begin(),dist[n].end());
    for(int i = 1; i <= k; i++) cout << dist[n][i] << ' ';
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

