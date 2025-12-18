#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
int n;
int adj[mx][mx];

vector<vector<int>> fw() {
    vector<vector<int>> dist(n + 1, vector<int> (n + 1));
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) dist[u][v] = adj[u][v];
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    return dist;
}

void solve() {
    cin >> n;
    vector<int> perm(n);
    iota(perm.begin(),perm.end(), 1);
    for(int i  = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = 1e9;
        }
        adj[i][i] = 0;
    }

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }


    double res = 0;
    double p = (double)1/(n * (n - 1));
    vector<vector<int>> dist = fw();
    for(int i = 1; i <= n; i++){
        double s = 0;
        for(int j = 1; j <= n; j++){
            double sum = 0;
            for(int k = 1; k <= n; k++){
                if(j == k) continue;
                sum += dist[j][k];
            }
            s += sum;
        }
        res += s * p;
    }
    /*
    for(int i = 1; i < n; i++){
        s += dist[i][i + 1];
    }
    res += s * p;
    while(next_permutation(perm.begin(),perm.end())){
       map<int,int> pos;
       for(int i = 0;i < n; i++){
           pos[perm[i]] = i + 1;
       }
       s = 0;
       for(int i = 1; i < n; i++){
           s += dist[pos[i]][pos[i + 1]];
       }
       res += s * p;
    }*/
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

