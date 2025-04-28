#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;cin >> n;
    if(n & 1) cout << n/2*(n/2+1) << endl;
    else cout << n/2*n/2 << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

