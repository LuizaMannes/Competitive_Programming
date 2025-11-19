#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
int n, k;
vector<int> ar(mx);
int dp[mx][105][2];

void solve() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> ar[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l < 2; l++){
                dp[i][j][l] = -1e9;
            }
        }
    }

    dp[0][0][0] = ar[0];
    dp[0][1][1] = -ar[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(j > 0) dp[i][j][1] = max({dp[i - 1][j - 1][0] - ar[i], dp[i - 1][j][1] - ar[i], -ar[i]});
            dp[i][j][0] = max({dp[i - 1][j][1] + ar[i], dp[i - 1][j][0] + ar[i], ar[i]});
        }
    }

    int res = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < 2; l++){
                res = max(res, dp[j][i][l]);
                //cout << dp[j][i][l] << " ";
            }
        }
       //cout << endl;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

