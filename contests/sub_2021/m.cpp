#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;

vector<int> adj[mx], vis(mx), ordem(mx);
int T = 0;

void dfs(int u){
    vis[u]++;
    ordem[T++] = u;

    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
    }
}

void solve() {
    int n; cin >> n;
    
    vector<int> q;
    int filho = 1;
    for(int i = 0; i < n; i++){
        int t, a; cin >> t >> a;
        if(t == 1){
            adj[a].push_back(++filho);
            adj[filho].push_back(a);
        }else q.push_back(a);
    }

    dfs(1);
    
    vector<int> m(filho + 1);
    int j = 0;
    for(int i: q){
        m[i] = 1;
        while(m[ordem[j]]) j++;

        cout << ordem[j] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

