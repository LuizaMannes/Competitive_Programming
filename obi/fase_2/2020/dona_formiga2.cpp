#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=205;

vector<int> adj[mx];
vector<int> alt(mx);
vector<int> dp(mx);
int vis[mx];

void dfs(int u){
    vis[u]++;

    bool f=true;
    for(auto v:adj[u]){
        if(!vis[v] && alt[v]<alt[u]){
            dfs(v);
        }
        if(alt[v]<alt[u]){
            f=false;
            dp[u]=max(dp[u],dp[v]+1);
        }
    }
    if(f && dp[u]==0) dp[u] = 1;
}


void solve() {
    int n,m,p;cin >> n >> m >> p;

    for(int i=1;i<=n;i++){
        int a;cin >> a;
        alt[i]=a;
    }

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(p);

    cout << dp[p]-1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


