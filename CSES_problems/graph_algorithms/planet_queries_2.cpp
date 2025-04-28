#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;
const int L=30;

vector<int> adj[mx];
int up[mx][L];
int dep[mx];
int vis[mx];
int n;

void dfs(int u){
    vis[u]=1;

    for(auto v:adj[u]){
        if(!vis[v]){
            dep[v]=dep[u]+1;
            dfs(v);
        }
    }
}

void bl(){
    for(int i=1;i<L;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}

int lca(int x,int y){
    int a=x;
    int b=y;
    if(dep[a]<dep[b]) swap(a,b);

    int k=dep[a]-dep[b];
    if(k){
        for(int i=0;i<L;i++){
            if(k & (1<<i)) a=up[a][i];
        }
    }

    for(int i=L-1;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }

    if(up[a][0]!=up[b][0]) return -1;
    
    int dif=dep[up[a][0]];
    return (dep[x]-dep[dif])+(dep[y]-dep[dif]);
} 

void solve() {
    int q;cin >> n >> q;
    
    for(int i=1;i<=n;i++){
        int a;cin >> a;
        dep[i]=0;
        up[i][0]=a;
        adj[i].push_back(a);
    }
    
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

    bl();

    while(q--){
        int a,b;cin >> a >> b;
        cout << lca(a,b) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

