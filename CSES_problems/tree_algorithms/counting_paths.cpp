#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx], tin(mx), tout(mx), res(mx), pai(mx);
int T = 0;

void dfs(int u, int p = -1){
    tin[u] = ++T;
    for(auto v: adj[u]){
        if(v != p){
            pai[v] = u;
            dfs(v, u);
        }
    }
    tout[u] = T;
}

void ans(int u, int p = -1){
    for(auto v: adj[u]){
        if(v != p){
            res[v] += res[u];
            ans(v, u);
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

    dfs(1);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        res[a]++;

        for(auto v: adj[a]){
            if(tout[v] < tout[b]) res[v]--;
        }

        for(auto v: adj[b]){
            if(v != pai[b]) res[v]--;
        }
    }

    ans(1);

    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

