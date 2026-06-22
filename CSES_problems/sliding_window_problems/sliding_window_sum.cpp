#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<int> ar(n);
    int l = 0, res = 0, sum = 0;
    for(int i = 0; i < n; i++){
        ar[i] = x;
        x = (a * x + b) % c;
        sum += ar[i];
        if(i - l + 1 == k) {
            res ^= sum;
            sum -= ar[l];
            l++;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

