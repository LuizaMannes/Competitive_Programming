#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;
const int L=20;

vector<int> adj[mx];
int up[mx][L];
int dep[mx];

void dfs(int u,int p){
    for(int i=1;i<L;i++) up[u][i]=up[up[u][i-1]][i-1];

    for(auto v:adj[u]){
        if(p!=v){
            dep[v]=dep[u]+1;
            up[v][0]=u;
            dfs(v,u);
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
            if(k & (1 << i )) a=up[a][i];
        }
    }

    if(a==b) return k;

    for(int i=L-1;i>=0;i--){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    int ca=up[a][0];
    int dif=(dep[x]-dep[ca])+(dep[y]-dep[ca]);

    return dif;
}

void solve() {
    int n,q;cin >> n >> q;
    
    for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dep[1]=0;
    up[1][0]=1;
    dfs(1,0);

    while(q--){
        int a,b;cin >> a >> b;
        cout << lca(a,b) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

