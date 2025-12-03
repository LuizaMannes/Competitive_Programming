#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 998244353;
const int mx = 1e6 + 6;

int dp[mx][2];

void solve() {
    int n, m; cin >> n >> m;
    
    dp[0][1] = m;
    dp[0][0] = 0;
    for(int i = 1; i < n; i++){
        dp[i][0] = (dp[i][0] + dp[i - 1][1] * (m - 1) + dp[i - 1][0] * (m - 2)) % mod;
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
    }
    cout << dp[n - 1][0] << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

