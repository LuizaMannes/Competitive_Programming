#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
vector<int> c(maxn), res(maxn), freq(2 * maxn), sub(maxn, 1), f(maxn);

void check(int u, int p){
    
    for(auto v : adj[u]){
        if(v != p){
            f[v] = f[u] + (c[v] == 1 ? 1 : -1);
            check(v, u);
            sub[u] += sub[v];    
        }
    }

}

void clean(int u, int p){

    for(auto v : adj[u]){
        if(v != p){
            clean(v, u);
        }
    }

    freq[abs(f[u]) + (f[u] < 0 ? maxn : 0)] = 0;

}

void add(int u, int p){

    for(auto v : adj[u]){
        if(v != p){
            add(v, u);
        }
    }

    freq[abs(f[u]) + (f[u] < 0 ? maxn : 0)]++;
}

void dfs(int u, bool keep, int p){
    int big = 0;
    for(auto v: adj[u]){
        if(v != p && sub[v] > sub[big]) big = v;
    }

    for(auto v: adj[u]){
        if(v != p && v != big){
            dfs(v, 0, u);
        }
    }
    
    if(big) dfs(big, 1, u);

    for(auto v: adj[u]){
        if(v != p && v != big){
            add(v, u);
        }
    }

    freq[abs(f[u]) + (f[u] < 0 ? maxn : 0)]++;

    res[u] = freq[abs(f[p]) + (f[p] < 0 ? maxn : 0)];

    if(!keep){
        freq[abs(f[u]) + (f[u] < 0 ? maxn : 0)] = 0;

        for(auto v: adj[u]){
            if(v != p){
                clean(v, u);
            }
        }

    }

}

void solve() {
    int n, q; cin >> n >> q;
    
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    f[1] = (c[1] == 1 ? 1 : -1);
    check(1, 0);
    sub[0] = 0;
    f[0] = 0;
    dfs(1, 1, 0);

    //for(int i = 1; i <= n; i++) cout << f[i] << " " << sub[i] << endl;
    while(q--){
        int u; cin >> u;
        cout << res[u] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

