#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=1010;

vector<int> adj[nmax];

vector<int> vis(nmax);

bool dfs(int u,int e, int s){
    vis[u]++;
    for(auto v:adj[u]){
        if(vis[v]==0 && v!=s){
            dfs(v,e,s);
        }
    }
    return vis[e]==1;
}

void solve() {
    int n,q;cin >> n >> q;
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<q;i++){
        int l,e,s;cin >> l >> e >> s;
        if(dfs(l,e,s)) cout << "SIM" << endl;
        else cout << "NAO" << endl;
        for(int j=0;j<=n;j++){
            vis[j]=0;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

