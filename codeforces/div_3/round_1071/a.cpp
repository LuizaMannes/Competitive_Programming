#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int k, x; cin >> k >> x;

    int i = 2;
    while(k){
        if((i - 1) % x == 0) k--;
        i++;
    }
    cout << i - 1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

