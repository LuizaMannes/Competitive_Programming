#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    if(n & 1){
        cout << 0 << endl;
        return;
    }

    int res = 1;
    while(n - 4>= 0){
        n -= 4;
        res++;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

