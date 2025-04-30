#include <bits/stdc++.h>

using namespace std;

const int nmax = 4005;

vector<int> adj[nmax];

vector<int> vis(nmax);

vector<pair<int,int>> dp(nmax);

int resp=0;

void dfs(int u){
    vis[u]++;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v);
            dp[u].first+=dp[v].first;
            dp[u].second+=dp[v].second;
        }
     

    }
    if(dp[u].first==dp[u].second) resp++;
}

void solve() {
   int n; cin >> n;
   
   for(int i=2;i<=n;i++){
        int a;cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
   }
   string s;cin >> s;
   for(int i=1;i<=s.size();i++){
        if(s[i-1]=='W'){
            dp[i].first++;
        } else{
            dp[i].second++;
        }

   }
   dfs(1);
   cout << resp << endl;
   for(int i=0;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
        dp[i].first=0;
        dp[i].second=0;
        resp=0;
   }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }
}

