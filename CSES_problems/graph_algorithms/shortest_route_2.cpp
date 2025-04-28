#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=505;
const int INF=1e18;
int n;

int adj[mx][mx];
int dist[mx][mx];

void floydwarshall() {
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            dist[u][v] = adj[u][v];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve() {
    int m, q; cin >> n >> m >> q;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j) adj[i][j]=0;
            else adj[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int a, b, c; cin >> a >> b >> c;
        if(adj[a][b]==INF){
            adj[a][b]=c;
            adj[b][a]=c;
        }else{
            adj[a][b]=min(adj[a][b],c);
            adj[b][a]=min(adj[b][a],c);
        }
    }

    floydwarshall();
    
    while(q--){
        int d, e; cin >> d >> e;
        if(dist[d][e]==INF) cout << -1 << endl;
        else cout << dist[d][e] << endl;
    }
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

