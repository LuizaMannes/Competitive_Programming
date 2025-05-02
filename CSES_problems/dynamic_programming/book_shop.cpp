#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e18;

void solve() {
    int n, x; cin >> n >> x;

    vector<int> a(n), b(n), dp(x + 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++){
        for(int j = x; j > 0; j--){
            if(a[i] > j) continue;

            dp[j] = max(dp[j], dp[j - a[i]] + b[i]); 
        }
    }
    
    cout << dp[x] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

