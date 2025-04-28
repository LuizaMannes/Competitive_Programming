#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = pair<int,int>;

const int mx=1e5+10;
const int INF=1e18;

vector<pair<int,int>> adj[mx];
vector<int> dist(mx, INF);

vector<int> dij(int s) {
    priority_queue<T, vector<T>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++){
       int a,b,c; cin >> a >> b >> c;
       adj[a].emplace_back(b,c);
    }

    dij(1);

    for(int i=1;i<=n;i++){
        cout << dist[i] << " \n" [i==n];
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

