#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5, LG = 20;

vector<int> adj[mx];
int up[mx][LG], tin[mx], tout[mx], sum[mx], t = 0;

void dfs(int u, int p = -1) {
    tin[u] = t++;
    for (int i = 0; i < LG - 1; i++) up[u][i + 1] = up[up[u][i]][i];
    for (int v : adj[u])
        if (v != p) {
            up[v][0] = u;
            dfs(v, u);
        }
    tout[u] = t;
}

bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = LG - 1; i >= 0; i--)
        if (!ancestor(up[u][i], v)) u = up[u][i];
    return up[u][0];
}

void res(int u, int p){
    for(auto v: adj[u]){
        if(v != p){
            res(v, u);
            sum[u] += sum[v];
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    up[1][0] = 1;
    dfs(1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        
        int c = lca(a,b);
        
        sum[a]++;
        sum[b]++;
        sum[c]--;
        if(c != 1) sum[up[c][0]]--;
    }

    res(1, 0);
    
    for(int i = 1; i <= n; i++){
        cout << sum[i] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

