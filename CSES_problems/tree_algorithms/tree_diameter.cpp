#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=2e5+5;

vector<int> adj[nmax];
int dist[nmax];

void dfs(int u,int p){
    for(auto v: adj[u]){
        if(p!=v){
            dist[v]=dist[u]+1;
            dfs(v,u);
        }
    }
}

void solve() {
    int n; cin >> n;

    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[1]=0;
    dfs(1,0);
    
    int maxd=0;
    int node=0;
    for(int i=1;i<=n;i++){
        if(dist[i]>maxd){
            maxd=dist[i];
            node=i;
        }
        dist[i]=0;
    }

    dfs(node,0);

    maxd=0;
    for(int i=1;i<=n;i++){
        maxd=max(maxd,dist[i]);
    }

    cout << maxd << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

