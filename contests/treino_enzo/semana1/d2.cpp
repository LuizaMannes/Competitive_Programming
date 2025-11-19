#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
 
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
vector<int> c(maxn), tin(maxn), tout(maxn), f(maxn), pai(maxn), ar(maxn);
int T = 0;

void dfs(int u, int p){
    T++;
    
    tin[u] = T;
    ar[T] = u;
    for(auto v : adj[u]){
        if(v != p){
            pai[v] = u;
            f[v] = f[u] + (c[v] == 1 ? 1 : -1);
            dfs(v, u);
         }
    }

    tout[u] = T;
}
 
void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> ind(2 * (n + 1));
    
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    f[1] = (c[1] == 1 ? 1 : -1);
    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        ind[abs(f[ar[i]]) + (f[ar[i]] < 0? n : 0)].push_back(i);        
        //cout << ar[i] << "  ";
    }
    //cout << endl;

    while(q--){
        int u; cin >> u;
        int s = abs(f[pai[u]]) + (f[pai[u]] < 0 ? n : 0);
        auto i = lower_bound(ind[s].begin(),ind[s].end(), tin[u]);
        auto j = upper_bound(ind[s].begin(),ind[s].end(), tout[u]);
        //cout << tin[u] <<  " "  << tout[u] << endl;
        cout << (j - i)  << endl;
    }
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
