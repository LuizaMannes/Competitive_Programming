#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

const int mx = 2e5 + 5;

basic_string<int> adj[mx];
int sz[mx], pai[mx], vis[mx], k1, k2;
ll res = 0;
ll t[2 * mx];

ll merge(ll a, ll b) { return a + b; }

inline int lc(int p) { return p * 2; }
inline int rc(int p) { return p * 2 + 1; }

void build(int n) {
    for (int i = 0; i < n; i++) t[i + n] = 0;
    for (int i = n - 1; i > 0; i--) t[i] = 0;
}

ll query(int l, int r, int n) {
    ll ansl = 0, ansr = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ansl = merge(ansl, t[l++]);
        if (r & 1) ansr = merge(t[--r], ansr);
    }
    return merge(ansl, ansr);
}

void update(int i, ll x, int n){
    i += n;
    t[i] = merge(t[i], x);
    for (i >>= 1; i > 0; i >>= 1) t[i] = merge(t[lc(i)], t[rc(i)]);
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

void updt(int u, int p, int x, int d = 1){
    if(d > k2) return;

    if(d <= sz[x]) update(d, 1, sz[x]);
    for (int v : adj[u]){
        if(v != p && !vis[v]){
            updt(v, u, x, d + 1);
        }
    }
}

void dfs_dis(int u, int p, int x, int d = 1) {
    if(d > k2) return;

    res += query(max(0, k1 - d), min(k2 - d, sz[x]), sz[x]);

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
    update(0, 1, sz[c]);

    for(auto v: adj[c]){
        if(!vis[v]){
            dfs_dis(v, c, c);
            updt(v, c, c);
        }
    }

    build(sz[c]);

    for(int v : adj[c]){
        if(!vis[v]){
            init_centroid(v, c);
        }
    }
}

void solve() {
    int n; cin >> n >> k1 >> k2;

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

