#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;
    
    vector<int> ar(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        pref[ar[i]]++;
    }

    for(int i = n - 1; i >= 0; i--) pref[i] += pref[i + 1];

    int isum = 0, fsum = 0;
    for(int i = 1; i <= n; i++){
        fsum += (pref[i] * (2 * n - pref[i] + 1)) / 2;
        isum += i * ar[i];
    }

    int res = fsum - isum;

    for(int i = 1; i <= n; i++){
        int x = fsum, y = isum;
        y -= i * ar[i];
        y += i * (ar[i] - 1);
        x -= (pref[ar[i]] * (2 * n - pref[ar[i]] + 1)) / 2;
        x += ((pref[ar[i]] - 1) * (2 * n - (pref[ar[i]] - 1) + 1)) / 2;
        res = max(res, x - y);
    }
    
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

