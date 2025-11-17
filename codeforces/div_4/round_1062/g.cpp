#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n), c(n), dp(n);
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        sum += c[i];
        dp[i] = c[i];
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], dp[j] + c[i]);
            }
        }
    }

    sort(dp.begin(), dp.end());
    cout << sum - dp[n - 1] << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

