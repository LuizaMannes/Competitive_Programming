#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = tuple<int,int,int>;

const int N = 3e3 + 5;
const int INF = 1e18;
int n;

int adj[N][N];
int dist[N][N];

void fl() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

void solve() {
    int m, q; cin >> n >> m >> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) {
                adj[i][j] = 0;
                dist[i][j] = 0;
                continue;
            }
            adj[i][j] = INF;
            dist[i][j] = INF;
        }
    }

    vector<T> r;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--;b--;
        r.push_back({a,b,c});
        adj[a][b] = c;
        adj[b][a] = c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    vector<T> qu;
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int a; cin >> a;
            a--;
            qu.push_back({t, a, 0});
            auto [u, v, c] = r[a];
            adj[u][v] = INF;
            adj[v][u] = INF;
            dist[u][v] = INF;
            dist[v][u] = INF;
        }else{
            int a, b; cin >> a >> b;
            a--;b--;
            qu.push_back({t, a, b});
        }
    }

    fl();

    vector<int> res;
    for(int l = q - 1; l >= 0; l--){
        auto [t,u,v] = qu[l];
        if(t == 2){
            res.push_back(dist[u][v] == INF? -1: dist[u][v]);
        }else{
            auto [a,b,c] = r[u];
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][a] + c + dist[b][j]);
                    dist[i][j] = min(dist[i][j], dist[i][b] + c + dist[a][j]);
                }
            }

        }
    }

    reverse(res.begin(),res.end());
    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

