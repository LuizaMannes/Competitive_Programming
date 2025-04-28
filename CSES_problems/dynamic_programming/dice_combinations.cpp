#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax = 1e6+5;
const int mod = 1e9+7;
vector<int> dp(nmax, -1);


int calc(int n){
    if(n < 0) return 0;

    if(n == 0 || n == 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    } else {
        dp[n] = calc(n - 1) + calc(n - 2) + calc(n - 3) + calc(n - 4) + calc(n - 5) + calc(n - 6);
        dp[n] %= mod;
        return dp[n];
    }

}

void solve(){
    int n; cin >> n;

    cout << calc(n) << endl;

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

