#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9+7;
const int INF = 1e9;

void solve() {
    int n, x; cin >> n >> x;
    
    vector<int> ar(n), dp(x + 1);
    for(int i = 0; i < n; i++) cin >> ar[i];

    sort(ar.begin(),ar.end());

    for(int i = 0; i < n; i++){
        if(ar[i] > x) break;
        dp[ar[i]]++;
        for(int j = 0; j <= x; j++){
            if(j + ar[i] > x) continue;
            dp[j + ar[i]] += dp[j];
            dp[j + ar[i]] %= mod;
        }
    }
    //for(int i = 0; i <= x; i++) cout << dp[i] << endl;
    cout << dp[x] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
