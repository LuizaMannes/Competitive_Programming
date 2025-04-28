#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> pref(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    pref[0] = a[0];
    for(int i = 1; i < n; i++)
        pref[i] = pref[i-1] + a[i];
    int q; cin >> q;
    while(q--){
        ll x, y, m; cin >> x >> y >> m;
        cout << min(y + pref[m-1], max(x, pref[n-1])) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int t = 1;
    while (t--) solve();
}