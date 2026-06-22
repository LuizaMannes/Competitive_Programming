#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int inv = 500000004;

void solve() {
    int n; cin >> n;

    int s = 0, i = 1;
    while(i <= n){
        int d = n / i;
        int a = n / d;

        int b = (((a - i + 1) % mod) * (((i + a) % mod) * inv % mod)) % mod;
        s = (s + d * b % mod) % mod;
        i = a + 1;
    }

    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

