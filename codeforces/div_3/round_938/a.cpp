#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m,o; cin >> n >> m >> o;
    if(2*m<o) cout << n*m << endl;
    else {
        if(n & 1) cout << m+n/2*o << endl;
        else cout << n/2*o << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}


