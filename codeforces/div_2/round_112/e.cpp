#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int LG = 22;

void solve() {
    int n; cin >> n;
    int inv = (1 << LG) - 1;
    vector<int> dp(1 << LG, -1);
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        dp[ar[i] ^ inv] = ar[i];
    }

    for(int i = (1 << LG); i >= 0; i--){
        for(int j = 0; j < LG; j++){
            if((i >> j) & 1){
                dp[i ^ (1 << j)] = max(dp[i ^ (1 << j)], dp[i]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dp[ar[i]] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

