#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = pair<int,int>;

const int mx=1e5+5;

vector<int> adj[mx];
vector<int> dist(mx);
int vis[mx];
int pai[mx];

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) dfs(v);

        if(dist[v]+1>dist[u] && dist[v]!=-1){
            pai[u]=v;
            dist[u]=max(dist[v]+1,dist[u]);
        }
    }
}

void res(){
    vector<int> path;

    for(int i=1;i!=-1;i=pai[i]){
        path.push_back(i);
    }
    //reverse(path.begin(),path.end());

    cout << path.size() << endl;
    for(auto c:path) cout << c << " ";
    cout << endl;

}

void solve() {
    int n,m;cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        dist[i]=-1;
        vis[i]=0;
        pai[i]=-1;
    }

    dist[n]=1;
    
    dfs(1);

    if(dist[1]==-1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }else res();
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

