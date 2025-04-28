#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

const int INF = 1e9;

void solve() {
    int n, k, c;cin >> n >> k >> c;
    
    vector<int> ar(n+1);
    vector<vector<int>> dp(k+1, vector<int> (n+1, -INF));

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        dp[0][i] = dp[0][i-1] + ar[i];
    }

    for(int i = 1; i <= k; i++){
        for(int j = i*c; j <= n; j++){
            dp[i][j] = max(dp[i-1][j-c], dp[i][j-1] + ar[j]);
        }
    }
    
    cout << dp[k][n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

