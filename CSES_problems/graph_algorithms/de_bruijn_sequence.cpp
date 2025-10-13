#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 15;
vector<int> adj[(1 << mx)], it(1 << mx), path;

void dfs(int u){
    while(it[u] < adj[u].size()){
        int v = adj[u][it[u]++];
        dfs(v);
    }
    path.push_back(u & 1); 
}

void solve() {
    int n; cin >> n;

    if(n == 1){
        cout << "10" << endl;
        return;
    }

    for(int i = 0; i < (1 << (n - 1)); i++){
        int a = (i << 1) % (1 << (n - 1));
        adj[i].push_back(a);
        adj[i].push_back(a | 1);
    }

    dfs(0);
    //reverse(path.begin(), path.end());
    for(int i = 0; i < n - 2; i++) path.push_back(0);

    for(int i: path) cout << i;
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

