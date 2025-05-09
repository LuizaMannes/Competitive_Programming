#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = pair<int, int>;

const int mx = 2e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

vector<T> adj[mx];
vector<int> dist(mx, inf), t(mx), nmin(mx), nmax(mx);

void dij(int s){
    dist[s] = 0;
    t[s] = 1;
    
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(dist[s], s);

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d != dist[u]) continue;
        for(auto [v, w]: adj[u]){
            if(dist[v] == d + w){
                t[v] = (t[v] + t[u]) % mod;
                nmin[v] = min(nmin[v], nmin[u] + 1);
                nmax[v] = max(nmax[v], nmax[u] + 1);
            }
            else if(dist[v] > d + w){
                t[v] = t[u];
                nmin[v] = nmin[u] + 1;
                nmax[v] = nmax[u] + 1;
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dij(1);

    cout << dist[n] << " " << t[n] << " " << nmin[n] << " " << nmax[n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

