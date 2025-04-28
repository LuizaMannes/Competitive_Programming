#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+10;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> tp;
int vis[mx];
int reinos[mx];

void dfs(int u){
    vis[u]++;
    for(auto v: adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
    tp.push_back(u);
}

void evil_dfs(int u, int aux){
    vis[u]++;
    reinos[u]=aux;
    for(auto v:jda[u]){
        if(vis[v]==0){
            evil_dfs(v,aux);
        }
    }
}

void solve() {
    // kosaraju
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) dfs(i);
    }

    for(int i=0;i<=n;i++) vis[i]=0;
    
    int aux=0;
    while(tp.size()){
        int b=tp.back();
        tp.pop_back();
        if(vis[b]==0){
            aux++;
            evil_dfs(b,aux);
        }
    }

    cout << aux << endl;
    for(int i=1;i<=n;i++){
        cout << reinos[i] << " \n" [i==n];
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

