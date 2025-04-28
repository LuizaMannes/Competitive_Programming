#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+10;
const int INF=1e9;

vector<pair<int,int>> adj[mx];
int dist[mx][105];
int k;

void bfs(int s){
    dist[s][0]=0;
    queue<pair<int,int>> q;
    q.emplace(s,0);
    while(!q.empty()){
        auto [u,g]=q.front();
        q.pop();
        for(auto [v,w]:adj[u]){
            if(w+g>k) continue;
            if(dist[v][w+g]==-1){
                dist[v][w+g]=dist[u][g]+1;
                q.emplace(v,w+g);
            }
        }
    }
}

void solve() {
    int n,m;cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dist[i][j]=-1;
        }
    }
    bfs(1);
    int res=INF;
    for(int j=0;j<=k;j++){
        if(dist[n][j]==-1)continue;
        res=min(res,dist[n][j]);
    }
    cout << (res==INF? -1 : res) << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

