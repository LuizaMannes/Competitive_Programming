#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;
const int L=20;

vector<int> adj[mx];
int up[mx][L];
int depth[mx];

void dfs(int u,int p){
    for(int i=1;i<L;i++) up[u][i]=up[up[u][i-1]][i-1];
    
    for(auto v:adj[u]){
        if(v!=p){
            depth[v]=depth[u]+1;
            up[v][0]=u;
            dfs(v,u);
        }
    }
}

int kth(int u,int k){
    if(k>=depth[u]) return -1;

    for(int i=0;i<L;i++){
        if(k & (1<<i)) u = up[u][i];
    }

    return u;
}

void solve() {
    int n,q;cin >> n >> q;

    for(int i=2;i<=n;i++){
        int a;cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    
    depth[1]=1;
    up[1][0]=1;
    dfs(1,0);
    
    while(q--){
        int u,k;cin >> u >> k;
        cout << kth(u,k) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

