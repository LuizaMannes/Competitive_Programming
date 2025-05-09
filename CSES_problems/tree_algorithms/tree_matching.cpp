#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

vector<int> adj[maxn];
int vis[maxn], res = 0;

void dfs(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            
            if(!vis[v] && !vis[u]){
                res++;
                vis[v] = 1; 
                vis[u] = 1;
            }
        }
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

