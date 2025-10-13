#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 21, mod = 1e9 + 7;

vector<int> adj[mx];
int dp[1 << mx][mx];

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--,b--;
        adj[b].push_back(a);
    }

    dp[1][0] = 1;
    for(int i = 2; i <= (1 << n); i++){
        if(!(i & 1) || (i & (1 << n) && i != ((1 << n) - 1))) continue;

        for(int j = 0; j < n; j++){
            if((i & (1 << j)) == 0) continue;

            for(auto v: adj[j]){
                if(i & (1 << v)){
                    dp[i][j] += dp[i ^ (1 << j)][v];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

