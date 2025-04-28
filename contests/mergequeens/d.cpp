#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5+5;


vector<pair<int,int>> adj[nmax];

vector<int> vis(nmax);

vector<int> dp(nmax);

void dfs(int u){
    vis[u]++;
    dp[u]=0;
    for(auto [v,x]:adj[u]){
        if(vis[v]==0){
            dfs(v);
            dp[u]=max(dp[u],dp[v]+x);
        }
            
    }

}

void solve() {
   int n; cin >> n;
   
   for(int i=1;i<n;i++){
        int u,v,x;cin >> u >> v >> x;
        adj[u].emplace_back(v,x);
        adj[v].emplace_back(u,x);
                
   }

   
   dfs(1);
   cout << dp[1] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    
}


