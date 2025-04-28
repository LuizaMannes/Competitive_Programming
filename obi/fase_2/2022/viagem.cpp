#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T=tuple<int,int,int>;

const int mx=1e4+5;
const int INF=1e18;

vector<T> adj[mx];
int dist[mx][210];
int maximo;

void dij(int s){
    dist[s][0]=0;
    priority_queue<T,vector<T>,greater<>> pq;
    pq.emplace(dist[s][0],0,s);
    while(!pq.empty()){
        auto [c,p,u]=pq.top();
        pq.pop();

        if(dist[u][p]!=c) continue;
        
        for(auto [w,d,v] : adj[u]){
            if(p+d>maximo) continue;
            if(dist[v][p+d]>c+w){
                dist[v][p+d]=c+w;
                pq.emplace(dist[v][p+d],p+d,v);
            }
        }
    }
}

void solve() {
    int n,m;cin >> maximo >> n >> m;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=maximo;j++){
            dist[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c,d;cin >> a >> b >> c >> d;
        adj[a].emplace_back(c,d,b);
        adj[b].emplace_back(c,d,a);
    }

    int x,y;cin >> x >> y;

    dij(x);
    
    int res=INF;
    for(int i=0;i<=maximo;i++){
        res=min(dist[y][i],res);
    }
    cout << (res==INF ? -1: res) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

