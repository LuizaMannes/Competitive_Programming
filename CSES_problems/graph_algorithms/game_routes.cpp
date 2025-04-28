#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+5;
const int MOD=1e9+7;

vector<int> adj[mx];
vector<int> dp(mx);
int vis[mx];
int n;
int res=0;

void dfs(int u){
    vis[u]=1;

    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }

        if(dp[v]!=0) dp[u]=(dp[u]+dp[v]) % MOD;
    }
}

void solve() {
    int m;cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
    }
    
    dp[n]=1;
    dfs(1);
    
    cout << dp[1] % MOD << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

