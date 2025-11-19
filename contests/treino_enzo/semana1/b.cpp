#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e3 + 3;

vector<pair<int,int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<string> adj;
int vis[mx][mx], comp[mx][mx], res[mx * mx];

int n, m;
bool pode(int i, int j){
    return i < n && i >= 0 && j < m && j >= 0 && !vis[i][j];
}

void dfs(int i, int j, int c){
    vis[i][j] = 1;
    comp[i][j] = c;
    for(auto [ii, jj]: moves){
        if(pode(i + ii, j + jj)){
            if(adj[i + ii][j + jj] == '*'){
                res[c]++;
                continue;
            }
            dfs(i + ii, j + jj, c);
        }
    }
}

void solve() {
    int q; cin >> n >> m >> q;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        adj.push_back(s);
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && adj[i][j] == '.'){
                dfs(i, j, c++);
            }
        }
    }

    while(q--){
        int i, j; cin >> i >> j;
        i--;j--;
        cout << res[comp[i][j]] << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

