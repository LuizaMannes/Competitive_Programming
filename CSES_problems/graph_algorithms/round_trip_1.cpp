#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+10;

vector<int> adj[mx];
vector<int> pai(mx);
vector<int> vis(mx);
int ini=-1,fim=-1;

bool dfs(int u, int pais){
    vis[u]++;
    for(auto v:adj[u]){
        if(v==pais) continue;
        if(vis[v]==0){
            pai[v]=u;
            if(dfs(v,pai[v])) return true;
        }else{
            ini=v;
            fim=u;
            return true;
        }
    }
    return false;
}


void solve() {
    int n,m; cin >> n >> m;
    vector<int> ci;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ciclo=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,pai[i])){
                ciclo=true;
                break;
            }
        }
    }

    if(!ciclo) cout << "IMPOSSIBLE" << endl;
    else{
        ci.push_back(ini);
        for(int i=fim;i!=ini;i=pai[i]){
            ci.push_back(i);
        }
        ci.push_back(ini);
        cout << ci.size() << endl;
        for(int i=0;i<ci.size();i++){
            cout << ci[i] << " \n" [i==ci.size()-1];
        }
    }
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

