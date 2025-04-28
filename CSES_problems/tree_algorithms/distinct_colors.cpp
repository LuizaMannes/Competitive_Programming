#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
vector<int> adj[maxn], c(maxn), res(maxn);
vector<set<int>> s(maxn);

void dfs(int u, int p){
    s[u].emplace(c[u]);

    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            if(s[u].size() < s[v].size()){
                s[u].swap(s[v]);
            }

            for(auto i : s[v]) s[u].emplace(i);
        }
    }

    res[u] = s[u].size();
}

void solve() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);

    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

