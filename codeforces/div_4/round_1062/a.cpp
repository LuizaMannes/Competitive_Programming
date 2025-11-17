#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a, b, c, d; cin >> a >> b >> c  >> d;
    if(a == b and b == c and c == d) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

