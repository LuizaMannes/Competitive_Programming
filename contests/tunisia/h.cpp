#include <bits/stdc++.h>
 #define int long long

using namespace std;
// using ll = long long;

void solve() {
    int n, m, a; cin >> n >> m >> a;
    cout << min((n - m), a) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int t; cin >> t;
    while (t--) solve();
}