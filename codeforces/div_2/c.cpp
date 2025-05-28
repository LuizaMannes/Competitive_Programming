#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;

vector<int> adj[mx], cats(mx), vis(mx);
int res = 0, m;

void dfs(int u, int c){
    vis[u]++;

    if(!cats[u]) c = m;
    if(cats[u]) c--;
    if(c < 0) return;

    bool folha = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            folha = 0;
            dfs(v, c);
        }
    }

    if(folha) res++;
}

void solve() {
    int n; cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> cats[i];

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, m);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

