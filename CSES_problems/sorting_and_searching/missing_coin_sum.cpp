#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    sort(ar.begin(), ar.end());

    int res = 1;
    for(int i = 0; i < n; i++){
        if(ar[i] > res) break;

        res += ar[i];
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

