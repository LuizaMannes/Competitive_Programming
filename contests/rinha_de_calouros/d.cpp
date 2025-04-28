#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m; cin >> n >> m;
    if(m & 1) cout << n << endl;
    else cout << n-n/(m+1) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

