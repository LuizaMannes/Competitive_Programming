#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n);

    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<int> res;
    for(int i = 0; i < n; i++) if(ar[i] % 6 == 0) res.push_back(ar[i]);
    for(int i = 0; i < n; i++) if(ar[i] % 6 != 0 and ar[i] % 2 == 0) res.push_back(ar[i]);
    for(int i = 0; i < n; i++) if(ar[i] % 3 != 0 and ar[i] % 2 != 0) res.push_back(ar[i]);
    for(int i = 0; i < n; i++) if(ar[i] % 6 != 0 and ar[i] % 3 == 0) res.push_back(ar[i]);

    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

