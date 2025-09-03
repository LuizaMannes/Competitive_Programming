#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int inf = 1e9 + 5;

void solve() {
    int n; cin >> n;

    vector<int> ar(n);

    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<int> dp(n + 1, inf);
    dp[0] = -inf;

    int res = 0;
    for(int i = 0; i < n; i++){
        int ind = lower_bound(dp.begin(), dp.end(), ar[i]) - dp.begin();
        if(dp[ind] > ar[i]) dp[ind] = ar[i];
        res = max(res, ind);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

