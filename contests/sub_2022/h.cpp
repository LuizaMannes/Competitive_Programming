#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e4+5;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> adj2[mx];
vector<int> tp;
int vis[mx];
int cont[mx];
vector<int> cor(mx,-1);
int r=0;
int f=0;

void topo(int u){
    vis[u]++;

    for(auto v:adj[u]){
        if(!vis[v]) topo(v);
    }

    tp.push_back(u);
}

void dfs(int u,int c){
    cor[u]=c;

    for(auto v:jda[u]){
        if(cor[v]==-1) dfs(v,c);
    }
}

void dfs2(int u){
    vis[u]++;
    bool folha = true;
    for(auto v: adj2[u]){
        if(!vis[v]){
            cont[v]++;
            dfs2(v);
        }
        folha = false;
    }
    if(folha){
        f++;
        //cout << u << endl;
    }
}

void solve() {
    int n,m;cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) topo(i);
    }

    int c=0;
    reverse(tp.begin(),tp.end());

    for(auto u:tp){
        if(cor[u]==-1) dfs(u,++c);
    }

    for(int i=1;i<=n;i++){
        for(auto v: adj[i]){
            if(cor[i]==cor[v]) continue;
            adj2[cor[i]].push_back(cor[v]);
        }
    }

    for(int i=1;i<=n;i++) vis[i]=0;
    
    for(int i=1;i<=c;i++){
        if(!vis[i]) dfs2(i);
        
    }
    
    for(int i=1;i<=c;i++){
        if(cont[i]==0) r++;
    }

    //for(int i=1;i<=n;i++) cout << cor[i] << " ";
    //cout << endl;

    /*for(int i=1;i<=n;i++){
        for(auto v:adj2[i]){
            cout << i << " " << v << endl;
        }
    }*/

    //cout << r << " " << f << endl;

    if(c==1){
        cout << 0 << endl;
        return;
    }

    cout << max(f,r) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

