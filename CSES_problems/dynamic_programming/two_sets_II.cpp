#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

int binexp(int b, int e) {
    int res = 1;
    b %= mod;
    while (e) {
        if (e & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return res % mod;
}

void solve() {
    int n, x; cin >> n;

    x = (n + 1) * n / 2;

    if(x & 1){
        cout << 0 << endl;
        return;
    }

    x /= 2;

    vector<int> dp(x + 1);

    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 1; j--){
            if(j + i > x) continue;
            dp[j + i] += dp[j];
            dp[j + i] %= mod;
        }
        dp[i]++;
        dp[i] %= mod;
    }

    int d = binexp(2, mod - 2);

    cout << (dp[x] * d) % mod << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
