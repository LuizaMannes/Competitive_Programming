#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2*1e3+600;
const int INF=1e10;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> vis(mx);
vector<int> siv(mx);
int n;

void dfs(int u){
    vis[u]++;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}

void evil_dfs(int u){
    siv[u]++;
    for(auto v:jda[u]){
        if(siv[v]==0){
            evil_dfs(v);
        }
    }
}

void solve() {
    //Belmann-Ford
    int m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<int> dp(mx,-INF);
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].emplace_back(b);
        jda[b].emplace_back(a);
        edges.emplace_back(a,b,c);
    }
    dfs(1);
    evil_dfs(n);
    dp[1]=0;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dp[v] < dp[u]+w) {
                dp[v] = dp[u]+w;
                if(i==n-1 && vis[v] && siv[v]){
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    cout << dp[n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


