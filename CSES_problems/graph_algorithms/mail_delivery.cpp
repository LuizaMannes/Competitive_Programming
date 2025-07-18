#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mxn = 1e5 + 5;
const int mxm = 2e5 + 5;

vector<pair<int,int>> adj[mxn];
int it[mxm], vis[mxm];
vector<int> res;

void dfs(int u){
    while(it[u] < adj[u].size()){
        auto [v, id] = adj[u][it[u]++];
        if(vis[id]) continue;
        vis[id] = 1;
        dfs(v);
    }

    res.push_back(u);
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for(int i = 1; i <= n; i++){
        if(adj[i].size() & 1){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }   

    dfs(1);
    if(res.size() != m + 1) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

