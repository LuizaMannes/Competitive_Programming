#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

const int mx = 2e5 + 5;

basic_string<int> adj[mx];
int sz[mx], pai[mx], dis[mx], vis[mx], k;
ll res = 0;

int find_size(int u, int p){
    if(vis[u]) return 0;
    sz[u] = 1;

    for(int v: adj[u]){
        if(v != p){
            sz[u] += find_size(v, u);
        }
    }

    return sz[u];
}

int find_centroid(int u, int p, int s){
    for(auto v: adj[u]){
        if(v != p){
            if(!vis[v] && sz[v] > s / 2){
                return find_centroid(v, u, s);
            }
        }
    }

    return u;
}

void updt(int u, int p, int x, int d = 1){
    if(d > k) return;

    if(d <= sz[x]) dis[d]++;
    for (int v : adj[u]){
        if(v != p && !vis[v]){
            updt(v, u, x, d + 1);
        }
    }
}

void dfs_dis(int u, int p, int x, int d = 1) {
    if(d > k) return;

    if(k - d <= sz[x]) res += dis[k - d];
    for(int v : adj[u]){
        if(v != p && !vis[v]){
            dfs_dis(v, u, x, d + 1);
        }
    }
}

void init_centroid(int u, int p){
    find_size(u, -1);

    int c = find_centroid(u, -1, sz[u]);
    vis[c] = 1;
    pai[c] = p;
    dis[0] = 1;

    for(auto v: adj[c]){
        if(!vis[v]){
            dfs_dis(v, c, c);
            updt(v, c, c);
        }
    }

    for(int i = 0; i <= sz[c]; i++) dis[i] = 0;

    for(int v : adj[c]){
        if(!vis[v]){
            init_centroid(v, c);
        }
    }
}

void solve() {
    int n; cin >> n >> k;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    init_centroid(1, -1);

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

