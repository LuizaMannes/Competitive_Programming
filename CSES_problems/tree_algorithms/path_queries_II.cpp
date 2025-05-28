#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx];
int sz[mx], pai[mx], head[mx], tin[mx], seg[2 * mx];
int T = 0, n;

void dfs(int u, int p = -1){
    sz[u] = 1;
    for(int &v: adj[u]){
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];

            if(sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
        }
    }
}

void hld(int u, int p = -1){
    tin[u] = ++T;
    for(int v: adj[u]){
        if(v != p){
            pai[v] = u;
            head[v] = (v == adj[u][0]? head[u]: v);
            hld(v, u);
        }
    }
}   

void seg_build(vector<int> &v){
    for(int i = 0; i < n; i++) seg[i + n] = v[i + 1];
    for(int i = n - 1; i > 0; i--) seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
}

void hld_build(int u, vector<int> &v){
    dfs(u);
    pai[u] = u, head[u] = u;
    hld(u);
    
    vector<int> aux(n + 1);
    for(int i = 1; i <= n; i++) aux[tin[i]] = v[i];
    seg_build(aux);
}

void update(int i, int x){
    i--;
    i += n;
    seg[i] = x;

    for(i >>= 1; i > 0; i >>= 1) seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
}

int seg_query(int l, int r){
    l--; r--;
    int resl = 0, resr = 0;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
        if(l & 1) resl = max(resl, seg[l++]);
        if(r & 1) resr = max(seg[--r], resr);
    }

    return max(resl, resr);
}

int query(int u, int v){
    int res = 0;
    while(head[u] != head[v]){
        if(tin[u] > tin[v]) swap(u, v);
        int qv = seg_query(tin[head[v]], tin[v]);
        res = max(qv, res);
        v = pai[head[v]];
    }
    if(tin[u] > tin[v]) swap(u, v);
    if(head[u] == head[v]){
        res = max(res, seg_query(tin[u], tin[v]));
    }

    return res;
}

void solve() {
    int q; cin >> n >> q;

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    hld_build(1, v);

    while(q--){
        int t, a; cin >> t >> a;

        if(t == 1){
            int x; cin >> x;
            update(tin[a], x);
        }else{
            int b; cin >> b;

            cout << query(a, b) << " ";
        }
    }

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

