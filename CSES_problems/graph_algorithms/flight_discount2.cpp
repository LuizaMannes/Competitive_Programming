#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T=tuple<int,int,int>;

const int mx=1e5+5;
const int INF=1e18;

vector<pair<int,int>> adj[mx];
int dist[mx][2];

void dij(int s){
    dist[s][0]=0;
    priority_queue<T,vector<T>,greater<>> pq;
    pq.emplace(dist[s][0],0,s);
    while(!pq.empty()){
        auto [c,d,u]=pq.top();
        pq.pop();

        if(c!=dist[u][d]) continue;

        for(auto [w,v] : adj[u]){
            if(!d){
                if(dist[v][1]>w/2+c){
                    dist[v][1]=w/2+c;
                    pq.emplace(dist[v][1],1,v);
                }
            }
            if(dist[v][d]>w+c){
                dist[v][d]=w+c;
                pq.emplace(dist[v][d],d,v);
            }
        }
    }
}

void solve() {
    int n,m;cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dist[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[a].emplace_back(c,b);
       // adj[b].emplace_back(c,a);
    }
    
    dij(1);

    cout << dist[n][1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

