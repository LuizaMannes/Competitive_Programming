#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, l, r; cin >> n >> l >> r;

    int qnt = r - l + 1;

    vector<int> ar(n), arl, arr;

    for(int i = 0; i < n; i++) cin >> ar[i];

    for(int i = 0; i < r; i++){
        arl.push_back(ar[i]);
    }

    for(int i = l - 1; i < n; i++){
        arr.push_back(ar[i]);
    }

    sort(arl.begin(),arl.end());
    sort(arr.begin(),arr.end());

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < r - l + 1; i++){
        sum1 += arl[i];
    }

    for(int i = 0; i < r - l + 1; i++){
        sum2 += arr[i];
    }

    int res = min(sum1, sum2);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

