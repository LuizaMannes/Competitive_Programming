#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    if((n & (n - 1)) == 0){
        cout << n - 1 << endl;
        return;
    }

    int lg = __lg(n);

    int ans = 0;
    int i = (1ll << lg), j = 1;

    while(j <= i){
        if((ans ^ i ^ j) <= n){
            ans ^= i;
            ans ^= j;
        }
        if(j == i) if((ans ^ i) <= n) ans ^= i;
        
        i >>= 1; j <<= 1;
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

