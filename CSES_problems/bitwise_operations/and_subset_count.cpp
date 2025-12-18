#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int LG = 22, mod = 1e9 + 7;

int bb(int base, int exp) {
    int b = base, res = 1;
    while (exp) {
        if (exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    vector<int> ar(n), dp(n + 1);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        dp[ar[i]]++;
    }

    for(int j = 0; j < LG; j++){
        for(int i = n; i >= 0; i--){
            if((i >> j) & 1){
                dp[i ^ (1 << j)] = (dp[i ^ (1 << j)] + dp[i]) % mod;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        dp[i] = bb(2, dp[i]) - 1;
    }

    for(int j = 0; j < LG; j++){
        for(int i = n; i >= 0; i--){
            if((i >> j) & 1){
                dp[i ^ (1 << j)] = (dp[i ^ (1 << j)] - dp[i]) % mod;  
            }
        }
    }

    for(int i = 0; i <= n; i++){
        cout << ((dp[i] % mod) + mod) % mod << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

