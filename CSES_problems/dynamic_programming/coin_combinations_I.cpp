#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
 
const int mod = 1e9+7;
 
void solve() {
    int n, x; cin >> n >> x;
    
    vector<int> ar(n), dp(x + 1);
    for(int i = 0; i < n; i++) cin >> ar[i];
 
    dp[0] = 1;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < n; j++){
            if(i + ar[j] > x) continue;
            dp[i + ar[j]] += dp[i];
            dp[i + ar[j]] %= mod;
        }
    }
 
    cout << dp[x] << endl;
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
