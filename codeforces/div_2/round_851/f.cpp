#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mx = 3e5;

vector<pair<int,int>> adj[mx];
int val[mx], sz[mx], pai[mx], deg[mx], x;

void dfs(int u, int i){
    if(deg[u]){
        sz[i]++; 
        x ^= val[u];
    }
    pai[u] = i;
    for(auto[v, c]: adj[u]){
        if(val[v] == -1){
            val[v] = val[u] ^ c;
            dfs(v, i);
        }
        if(val[v] != (val[u] ^ c)){
            cout << "No" << endl;
            exit(0);
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;

    vector<pair<int,int>> edges(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        edges[i] = {a,b};
        deg[a] ^= 1;
        deg[b] ^= 1;
    }

    for(int i = 0; i < q; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }

    memset(val, -1, sizeof(val));
    for(int i = 1; i <= n; i++){
        if(val[i] == -1){
            val[i] = 0;
            dfs(i, i);
        }
    }

    for(int i = 1; i <= n; i++){
        if(sz[i] & 1){
            for(int j = 1; j <= n; j++){
                if(pai[j] == i) val[j] ^= x;
            }
            break;
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < n - 1; i++){
        auto [u,v] = edges[i];
        cout << (val[u] ^ val[v]) << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

