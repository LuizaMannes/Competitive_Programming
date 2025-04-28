#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

int bexp(int n){
    int res = 1, a = 2;
    while(n){
        if(n & 1) res = (res * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }

    return res % mod;
}

void solve() {
    int n; cin >> n;
    int res = bexp(n);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

