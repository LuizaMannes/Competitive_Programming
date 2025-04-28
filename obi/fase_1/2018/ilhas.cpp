#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = pair<int,int>;

const int mx=1e3+10;
const int INF=1e9;

vector<pair<int,int>> adj[mx];
vector<int> dist(mx,INF);

void dij(int s){
    dist[s]=0;
    priority_queue<T,vector<T>,greater<>> pq;
    pq.emplace(s,dist[s]);
    while(!pq.empty()){
        auto [u,c] = pq.top();
        pq.pop();
        if(c!=dist[u]) continue;
        for(auto [v,w] : adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.emplace(v,dist[v]);
            }
        }
    }
}

void solve() {
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;  
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    int s;cin >> s;
    dij(s);
    int menor=INF;
    int maior=0;
    for(int i=1;i<=n;i++){
        if(i==s) continue;
        menor=min(menor,dist[i]);
        maior=max(maior,dist[i]);
    }
    cout << maior-menor << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

