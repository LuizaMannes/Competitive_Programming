#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int dif = abs(a - b);

    cout << (dif == 1 || dif & 1 ? "NO" : "YES") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

