#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e4 + 5;
int n, m;
vector<pair<int,int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> adj[maxn], radj[maxn], topo, comp(maxn, -1), vis(maxn);

bool pode(int i, int j){
    return i < n && j < m && i >=0 && j >= 0;
}

int get(int u){
    if(u < 0) return 2 * (~u) + 1;
    else return 2 * u;
}

void add_impl(int u, int v){
    u = get(u), v = get(v);
    
    adj[u].push_back(v);
    radj[v].push_back(u);
    adj[v ^ 1].push_back(u ^ 1);
    radj[u ^ 1].push_back(v ^ 1);
}

void add_xor(int u, int v){
    add_impl(u, ~v);
    add_impl(~u, v);
}

void tp(int u){
    vis[u]++;
    
    for(auto v: adj[u]){
        if(!vis[v]) tp(v);
    }

    topo.push_back(u);
}

void dfs(int u, int c){
    comp[u] = c;

    for(auto v: radj[u]){
        if(comp[v] == -1) dfs(v, c);
    }
}

void solve() {
    cin >> n >> m;
    
    vector<vector<int>> ar(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(auto [ii, jj] : mv){
                int x = ii + i;
                int y = jj + j;
                if(pode(x, y)){
                    if(ar[i][j] == ar[x][y]){
                        add_xor(i * m + j, x * m + y);
                    }
                    if(ar[i][j] + 1 == ar[x][y]){
                        add_impl(i * m + j, x * m + y);
                    }
                }
            }
        }
    }

    for(int i = 0; i < 2 * m * n; i++){
        if(!vis[i]) tp(i);
    }

    reverse(topo.begin(),topo.end());

    int c = 1;
    for(auto u: topo){
        if(comp[u] == -1) dfs(u, c++);
    }

    vector<bool> res(2 * m * n, false);
    for(int i = 0; i < 2 * m * n; i+= 2){
        res[i / 2] = comp[i] > comp[i+1];
    }
    
    int x = 0, y = 0;
    for(int i = 0; i < n * m; i++){
        if(res[i]) cout << ar[x][y] + 1 << " ";
        else cout << ar[x][y] << " ";

        y++;
        if(y == m){
            y = 0;
            x++;
            cout << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

