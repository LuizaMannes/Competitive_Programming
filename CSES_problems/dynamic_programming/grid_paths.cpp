#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;

    vector<string> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<vector<int>> dp(n, vector<int> (n));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ar[i][j] == '*') continue;
            if(i < n - 1 && ar[i + 1][j] != '*') dp[i + 1][j] += dp[i][j] % mod;
            if(j < n - 1 && ar[i][j + 1] != '*') dp[i][j + 1] += dp[i][j] % mod;
        }
    }

    if(n == 1 && ar[0][0] == '*'){
        cout << 0 << endl;
        return;
    }

    /*for(int i = 0 ;i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[n - 1][n - 1] % mod << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

