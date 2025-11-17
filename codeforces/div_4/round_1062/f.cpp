#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
using ll = long long;

const int mx = 2e5 + 5;
vector<int> adj[mx];
int sz[mx], res = 0, k;

void size_dfs(int u, int p = 0){
    sz[u] = 1;
    for(auto v: adj[u]){
        if(v != p){
            size_dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u, int p = 0){
    for(auto v: adj[u]){
        if(v != p) {
            dfs(v,u);
            int s = (sz[1] - sz[v]);
            if(s >= k) res += sz[v];
        }else{
            if(sz[u] >= k) res += sz[1] - sz[u];
        }
    }
}


void solve() {
    int n; cin >> n >> k;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    size_dfs(1);
    dfs(1);
    res += n;
    cout << res << endl;

    res = 0;
    for(int i = 0; i <= n; i++){
        sz[i] = 0;
        adj[i].clear();
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}
