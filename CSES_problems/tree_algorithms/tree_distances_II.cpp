#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx], dist(mx), sz(mx), res(mx);

void dfs(int u, int p = -1){
    sz[u] = 1;

    for(auto v: adj[u]){
        if(v != p){
            dist[v] = dist[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void ans(int u, int p = -1){
    int sz_up = sz[1] - 1 - sz[u];
    int sz_down = sz[u] - 1;
    if(u != 1) res[u] = res[p] + sz_up - sz_down;
    for(auto v: adj[u]){
        if(v != p){
            ans(v, u);
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

    dfs(1);
    for(int i = 1; i <= n; i++) res[1] += dist[i];

    ans(1);

    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

