#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
   int ar[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> ar[i][j];
        }
    }
 
    int dp[6][6][6] = {0};
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++) dp[i][0][j] = ar[i][0];
    }
 
    for(int i = 1; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                for(int l = 0; l < 6; l++){
                    if(j == l) continue;
                    if(l == k) continue;
                    dp[j][i][k] = max(dp[j][i][k], dp[l][i - 1][j] + ar[j][i]);
                }
            }
        }
    }
 
    int res = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++) res = max(res, dp[i][5][j]);
    }
 
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

