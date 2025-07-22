#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 5e3 + 5;
const int inf = 1e9 + 9;
vector<int> ar(mx);
vector<vector<int>> dp(mx,vector<int> (mx,inf));
int n;

int res(int i, int j){
    if(i > j) return 0;

    if(dp[i][j] != inf) return dp[i][j];

    dp[i][j] = max(min(ar[i] + res(i + 2, j), ar[i] + res(i + 1, j - 1)),
                min(ar[j] + res(i + 1, j - 1), ar[j] + res(i, j - 2)));

    return dp[i][j];
}

void solve() {
    cin >> n;

    for(int i = 0; i < n; i++) cin >> ar[i];
    
    cout << res(0, n - 1) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

