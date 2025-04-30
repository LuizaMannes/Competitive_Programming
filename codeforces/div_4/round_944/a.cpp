#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m; cin >> n >> m;
    int p = min(n,m), q = max(n,m);
    cout << p << ' ' << q << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

