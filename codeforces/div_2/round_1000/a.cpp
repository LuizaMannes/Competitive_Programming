#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int l, r; cin >> l >> r;

    if( l == 1 && r == 1){
        cout << 1 << endl;
        return;
    }

    cout << r - l << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

