#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
vector<int> vis(maxn);

void dfs(int u, int p){
    vis[u]++;

    for(auto v: adj[u]){
        if(vis[v] == 0){
            dfs(v, u);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int contc = -1;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i, 0);
            contc++;
        }
 
    }

    if(m + contc > n - 1|| contc) cout << "RUIM " << (m + contc) - (n - 1) << " " << contc << endl;
    else cout << "BOM" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

