#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

const int nmax=1e5+5;

vector<int> adj[nmax];
vector<int> vis(nmax);
vector<int> cores(nmax);


bool dfs(int u, int cor){
    vis[u]++;
    for(auto v:adj[u]){
        if(vis[v]==0){
            cores[v]=cor;
            if (!dfs(v,cor^1)) return false;
        }else{
            if(cores[u]==cores[v]) return false;
        }
    }
    return true;
}

void solve() {
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok=true;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(!dfs(i,1)){
                ok=false;
                break;
            }
        }
        //cout << cores[i] << ' ';
    }
    //cout << endl;
    
    vector<int> saco1;
    vector<int> saco2;

    for(int i=1;i<=n;i++){
        if(cores[i]==0) saco1.push_back(i);
        else saco2.push_back(i);
    }
   
    if(ok){
        cout << "POSSIVEL" << endl;
        cout << saco1.size() << " " << saco2.size() << endl;
        for(auto a:saco1) cout << a << " ";
        cout << endl;
        for(auto b:saco2) cout << b << " ";
        cout << endl;
    }else cout << "IMPOSSIVEL" << endl; 


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

