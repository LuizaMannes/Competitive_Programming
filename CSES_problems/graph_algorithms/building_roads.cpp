#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1e5+10;
vector<int> adj[nmax];
vector<int> vis(nmax);

void dfs(int u){
    vis[u]++;
    for(auto v: adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int aux=0;
    vector<int> res;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            aux++;
            res.push_back(i);
        }
    }
    cout << aux-1 << endl;
    if(aux-1==0) return;
    for(int i=1;i<res.size();i++){
        cout << 1 << " " << res[i] << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

