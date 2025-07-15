#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
const int inf = 1e9;
const int L = 20;

vector<int> adj[mx], vis(mx), depth(mx), sz(mx), pai(mx, -1), best(mx, inf);
int up[mx][L];

void dfs(int u, int p){
    for(int i = 1; i < L; i++) up[u][i] = up[up[u][i - 1]][i - 1];

    for(auto v: adj[u]){
        if(v != p){
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            dfs(v, u);
        }
    }
}

int kth(int u, int k){
    for(int i = 0; i < L; i++) if(k & (1 << i)) u = up[u][i];

    return u;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int k = depth[u] - depth[v];
    u = kth(u, k);

    if(u == v) return u;

    for(int i =  L - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int get_dist(int u, int v){
    int d = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[d];
}

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

void init_centroid(int u, int p){
    find_size(u, 0);

    int c = find_centroid(u, 0, sz[u]);
    vis[c] = 1;
    pai[c] = p;

    for(int v : adj[c]){
        if(!vis[v]){
            init_centroid(v, c);
        }
    }
}

void update(int u){
    best[u] = 0;

    int v = u;
    while(pai[v] != -1){
        v = pai[v];
        best[v] = min(best[v], get_dist(u, v));
    }
}

int query(int u){
    int res = best[u];

    int v = u;
    while(pai[v] != -1){
        v = pai[v];
        res = min(res, best[v] + get_dist(u, v));
    }

    return res;
}

void solve() {
    int n, q; cin >> n >> q;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    depth[1] = 0;
    up[1][0] = 1;
    dfs(1, 0);

    init_centroid(1, -1);

    update(1);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int u; cin >> u;
            update(u);
        }else{
            int u; cin >> u;
            cout << query(u) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


