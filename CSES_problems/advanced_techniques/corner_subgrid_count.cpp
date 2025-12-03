#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void solve() {
    int n; cin >> n;
    bitset<3001> ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];

    long long res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long c = (ar[i]&ar[j]).count();
            res += c * (c - 1) / 2;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

