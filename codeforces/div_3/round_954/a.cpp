#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    vector<int> ar(3);
    cin >> ar[0] >> ar[1] >> ar[2];
    sort(ar.begin(),ar.end());
    cout << abs(ar[0]-ar[1]) + abs(ar[1]-ar[2]) << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

