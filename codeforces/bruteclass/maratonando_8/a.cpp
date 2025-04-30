#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+10;

vector<int> adj[mx];
vector<int> folhas(mx);

void dfs(int u,int pai){
    bool folha=true;
    for(auto v:adj[u]){
        if(v!=pai){
            folha=false;
            dfs(v,u);
            folhas[u]+=folhas[v];
        }
    }
    if(folha) folhas[u]=1;
}

void solve() {
    int n;cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    int q;cin >> q;
    for(int i=0;i<q;i++){
        int a,b;cin >> a >> b;
        cout << folhas[a]*folhas[b] << endl;
    }

    for(int i=0;i<=n;i++){
        adj[i].clear();
        folhas[i]=0;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

