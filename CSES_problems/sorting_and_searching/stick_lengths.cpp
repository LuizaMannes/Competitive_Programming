#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    sort(ar.begin(), ar.end());

    int mid = ar[(n / 2)], res = 0;
    for(int i = 0; i < n; i++){
        res += abs(mid - ar[i]);
    }

    if(!(n & 1)){
        int mid2 = ar[n / 2 - 1], res2 = 0;
        for(int i = 0; i < n; i++){
            res2 += abs(mid2 - ar[i]);
        }

        res = min(res, res2);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

