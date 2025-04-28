#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+10;

vector<int> adj[mx];
vector<int> times(mx);
vector<int> vis(mx);

bool dfs(int u, int time){
    vis[u]++;
    for(auto v: adj[u]){
        if(vis[v]==0){
            times[v]=time;
            if(!dfs(v,time^1)) return false;
        }else{
            if(times[v]==times[u]) return false;
        }
    }
    return true;
}

void solve() {
    int n, m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    bool ok=true;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(!dfs(i,1)){
                ok=false;
            }
        }
    }

    if(!ok) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1;i<=n;i++){
            if(times[i]==0) cout << "1" << " \n" [i==n];
            else cout << "2" << " \n" [i==n];
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

