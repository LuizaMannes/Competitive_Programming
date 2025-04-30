#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+10;

vector<int> adj[mx];
int dep[mx],vis[mx],sz[mx],low[mx];
int c=0;
int n;

void dfs(int u, int p){
    low[u]=dep[u]=dep[p]+1;
    vis[u]++;

    for(auto v:adj[u]){
        if(p!=v){
            if(!vis[v]){
                dfs(v,u);
                sz[u]+=sz[v];
                low[u]=min(low[u],low[v]);
            }else{
                low[u]=min(low[u],dep[v]);
            }
        }
    }
    if(p!=0 && low[u]==dep[u]){
        c=max(c,sz[u]*(n-sz[u]));
    }
}

void solve() {
    int m;cin >> n >> m;
    
    for(int i=0;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
        sz[i]=1;
        dep[i]=0;
        low[i]=0;
    }
    c=0;

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    cout << n*(n-1)/2-c << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

