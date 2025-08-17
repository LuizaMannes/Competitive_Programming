#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx];
int vis[mx], dp[mx];

void dfs(int u){
    vis[u]++;

    dp[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && ar[s.top()] < ar[i]){
            adj[s.top()].push_back(i);        
            s.pop();
        }

        s.emplace(i);
    }

    while(!s.empty()) s.pop();

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && ar[s.top()] < ar[i]){
            adj[s.top()].push_back(i);        
            s.pop();
        }
        s.emplace(i);
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i);
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dp[i]);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

