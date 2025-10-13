#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 3e5 + 5, inf = 1e9, mod = 998244353;

vector<int> adj[mx];
int res[mx], mxdist = 0;
vector<int> dep(mx), dist(mx, -inf);

void bfs(int s){
    res[1] = res[2] = 1;
    dist[s] = dep[1] = 1;
    queue<int> q;
    q.emplace(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(res[dist[u]] == 0){
            if(res[dist[u] - 1] == 0) res[dist[u]] = 0;
            else res[dist[u]] = (res[dist[u] - 1] * (dep[dist[u] - 1] - 1)) % mod; 
        }
        
        for(int v: adj[u]){
            if(dist[v] == -inf){
                dist[v] = dist[u] + 1;
                dep[dist[v]]++;
                mxdist = max(mxdist, dist[v]);
                q.emplace(v);
            }
        }
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 2; i <= n; i++){
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    bfs(1);

    int ans = 0;
    for(int i = 1; i <= mxdist; i++) ans = (ans + (res[i] * dep[i])) % mod;

    cout << ans << endl;

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        dist[i] = -inf;
    }

    for(int i = 0; i <= mxdist; i++){
        res[i] = 0;
        dep[i] = 0;
    }
    mxdist = 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

