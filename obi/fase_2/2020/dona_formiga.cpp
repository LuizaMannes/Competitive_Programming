#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=205;

vector<int> adj[mx];
vector<int> alt(mx);
int vis[mx];

void dfs(int u){
    vis[u]++;

    for(auto v:adj[u]){
        if(!vis[v] && alt[v]<alt[u]) dfs(v);
    }
    
}

void solve() {
    int n,m,p;cin >> n >> m >> p;

    for(int i=1;i<=n;i++){
        int a;cin >> a;
        alt[i]=a;
    }

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(p);

    int res=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) res++;
    }

    cout << res-1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

