#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;

vector<int> adj[mx], radj[mx], cadj[mx], ar(mx), ciclos(mx, -1), dp(mx), topo;
int vis[mx];

void tp(int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) tp(v);
    }

    topo.push_back(u);
}

void dfs(int u, int c){
    ciclos[u] = c;

    for(auto v: radj[u]){
        if(ciclos[v] == -1) dfs(v, c);
    }
}

void res(int u){
    vis[u] = 1;

    bool f = 1;
    for(auto v: cadj[u]){
        f = 0;
        if(!vis[v]){
            res(v);
        }
        dp[u] = max(dp[u], ar[u] + dp[v]);
    }

    if(f) dp[u] = ar[u];
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) if(!vis[i]) tp(i);

    reverse(topo.begin(), topo.end());
    for(auto i: topo){
        if(ciclos[i] == -1){
            dfs(i, i);
        }
        ar[ciclos[i]] += a[i];
    }

    for(int i = 1; i <= n; i++){
       for(auto v: adj[i]){
            if(ciclos[i] == ciclos[v]) continue;
            cadj[ciclos[i]].push_back(ciclos[v]);
       }
    }

    for(int i = 1; i <= n; i++) vis[i] = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[ciclos[i]]) res(ciclos[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

