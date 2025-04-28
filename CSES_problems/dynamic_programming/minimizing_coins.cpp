#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e9;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> ar(n), dp(x + 1, INF);

    for(int i = 0; i < n; i++) cin >> ar[i];

    dp[0] = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < n; j++){
            if(i + ar[j] > x) continue;
            dp[i + ar[j]] = min(dp[i + ar[j]], dp[i] + 1);
        }
    }

    if(dp[x] == INF) cout << -1 << endl;
    else cout << dp[x] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

