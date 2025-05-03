#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int inf = 1e9 + 9;

void solve() {
    int n; cin >> n;
    
    int res = -inf, m = -inf;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m = max(a, m + a);

        res = max(res, m);
    }
    
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

