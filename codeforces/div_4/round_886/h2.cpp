#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T=pair<int,int>;

const int mx=2*1e5+10;
const int INF=1e18;

vector<pair<int,int>> adj[mx];
vector<int> dist(mx,INF);
vector<int> vis(mx);

bool dfs(int u){
    for(auto [w,v]:adj[u]){
        if(dist[v]==INF){
            dist[v]=dist[u]+w;
            if(!dfs(v)) return false;
        }else{
            if(dist[v]!=dist[u]+w) return false;
        }
    }
    return true;
}

void solve() {
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].emplace_back(-c,b);
        adj[b].emplace_back(c,a);
    }
    bool ok=true;
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            dist[i]=0;
            if(!dfs(i)) ok=false;
        }
    }
    cout << (ok?"YES":"NO") << endl;
    for(int i=0;i<=n;i++){
        dist[i]=INF;
        adj[i].clear();
        vis[i]=0;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}


