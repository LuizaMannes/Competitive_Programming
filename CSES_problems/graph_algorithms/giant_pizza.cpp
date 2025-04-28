#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> comp(mx,-1);
vector<int> topo;
vector<int> vis(mx);

void tp(int u){
    vis[u]++;
    for(auto v:adj[u]){
        if(!vis[v]) tp(v);
    }
    topo.push_back(u);
}

void dfs(int u,int c){
    comp[u]=c;
    for(auto v:jda[u]){
        if(comp[v]==-1) dfs(v,c);
    }
}

int get(int u){
    if(u < 0) return 2 * (~u) + 1;
    else return 2 * u;
}

void solve() {
    int n,m;cin >> n >> m;

    for(int i=0;i<n;i++){
        char a,b; int u,v;
        cin >> a >> u >> b >> v;
        if(a=='-') u=~u;
        if(b=='-') v=~v;

        u=~u;

        u=get(u); v=get(v);
        adj[u].push_back(v);
        adj[v ^ 1].push_back(u ^ 1);
        jda[v].push_back(u);
        jda[u ^ 1].push_back(v ^ 1);
    }

    for(int i=1;i<=m*2;i++){
        if(!vis[i]) tp(i);
    }

    reverse(topo.begin(),topo.end());
    
    int c=1;
    for(auto u:topo){
        if(comp[u]==-1) dfs(u,c++);
    }

    vector<bool> res(m,false);
    for(int i=2;i<=m*2;i+=2){
        if(comp[i]==comp[i+1]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        res[i/2] = comp[i] > comp[i+1];
    }

    for(int i=1;i<=m;i++){
        cout << (res[i]? '+' : '-') << ' ';
    } 
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

