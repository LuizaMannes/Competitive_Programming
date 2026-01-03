#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    int s = 0;
    for(int i = 1; i < n; i++) s += abs(ar[i] - ar[i - 1]);

    int res = min(s - abs(ar[1] - ar[0]), s - abs(ar[n - 1] - ar[n - 2]));
    for(int i = 1; i < n - 1; i++){
        res = min(res, s - abs(ar[i + 1] - ar[i]) - abs(ar[i] - ar[i - 1]) + abs(ar[i + 1] - ar[i - 1]));
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

