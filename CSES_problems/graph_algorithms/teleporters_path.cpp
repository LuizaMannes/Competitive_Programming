#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;

vector<int> adj[mx], cur;
int it[mx], in[mx], out[mx];

void dfs(int u){
    while(it[u] < adj[u].size()){
        int v = adj[u][it[u]++];
        dfs(v);
    }
    cur.push_back(u);
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
        out[a]++;
    }

    int start = -1, end = -1;
    for (int i = 1; i <= n; i++) {
        if (in[i] != out[i]) {
            if (in[i] == out[i] - 1)
                if (start == -1) start = i;
                else {
                    start = -1;
                    break;
                }
            else if (in[i] - 1 == out[i])
                if (end == -1) end = i;
                else {
                    end = -1;
                    break;
                }
            else {
                start = end = -1;
            }
        }
    }

    if(start != 1 || end != n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

   dfs(1);

   if(cur.size() != m + 1){
       cout << "IMPOSSIBLE" << endl;
       return;
   }

   reverse(cur.begin(), cur.end());

   for(int i: cur) cout << i << " ";
   cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

