#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int x, y; cin >> x >> y;

    if(x + 1 == y) cout << "Yes" << endl;
    else if((x + 1) % 9 == y % 9 && x > y) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

