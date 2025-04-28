#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+5;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> tp;
vector<int> vis(mx);
int cor[mx];
int pai[mx];
int ini=0;
int fim=0;

void dfs(int u){
    vis[u]=1;
    
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }

    tp.push_back(u);
}

bool sfd(int u,int c){
    vis[u]=1;
    cor[u]=c;
    for(auto v: jda[u]){
        if(!vis[v]){
            pai[v]=u;
            if(sfd(v,c)) return true;
        }else{
            if(cor[u]==cor[v]){
                pai[v]=u;
                ini=u;
                fim=v;
                return true;
            }
        }
    }

    return false;
}

void solve() {
    int n,m;cin >> n >> m;
    
    vector<int> ciclo;

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }

    for(int i=0;i<=n;i++) vis[i]=0;

    bool tem=false;
    int c=0;
    while(tp.size()){
        int a=tp.back();
        tp.pop_back();

        if(!vis[a]){
            if(sfd(a,++c)){
               tem=true;
               break;
            }
        }
    }

    ciclo.push_back(ini);
   // cout << ini << " " << fim << endl;

    for(int i=ini;i!=fim;i=pai[i]) ciclo.push_back(pai[i]);
    
    ciclo.push_back(ini);

    if(tem){
        cout << ciclo.size() << endl;

        for(auto c: ciclo) cout << c << " ";
        cout << endl;
    }else cout << "IMPOSSIBLE" << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

