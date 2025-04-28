#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e18;

void solve() {
    int n, x; cin >> n >> x;

    vector<int> a(n + 1), b(n + 1);
    int maxv = 0;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        maxv += b[i];
    }
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dp(maxv + 1, INF);
    dp[0] = 0;
    for(int i = 0; i <= maxv; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i] != INF && i + a[j] <= maxv){
                dp[i + a[j]] = min(dp[i + a[j]], dp[i] + b[j]);
            }
        }
    }

    //vector<vector<int>> dp(n + 1, vector<int> (x + 1, -INF));

    //dp[0][0] = 0;
    /*for(int i = 1; i < n + 1; i++){
        for(int j = 0; j <= x; j++){
            if(j - b[i] < 0){
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
        } 
    }*/

    int res = 0;
    for(int i = 0; i <= maxv; i++){
        if(dp[i] <= x) res = i;
    }
    cout << dp[16] << endl;
    //for(int j = 0; j <= x; j++){
        //res = max(res, dp[n][j]);
    //}

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

