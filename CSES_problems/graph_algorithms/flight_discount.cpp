#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = pair<int, int>;

const int mx=1e5+10;
const int INF=1e18;    

int tsid[mx];
int dist[mx];

int n;

void dij(int s, vector<pair<int,int>> adj[], int dist[]) {
    priority_queue<T, vector<T>, greater<>> pq;
    for(int i=0;i<=n;i++) dist[i]=INF;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [w, v] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void solve() {
    int m;cin >> n >> m;
    vector<tuple<int,int,int>> edges;
    vector<pair<int,int>> adj[mx];
    vector<pair<int,int>> jda[mx];
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        edges.emplace_back(a,b,c);
        adj[a].emplace_back(c,b);
        jda[b].emplace_back(c,a);
    }
    dij(1,adj,dist);
    dij(n,jda,tsid);
    int res=INF;
    for(auto [a,b,c] : edges){
        res=min(res,dist[a]+tsid[b]+c/2);
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

