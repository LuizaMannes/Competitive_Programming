#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,d,k;cin >> n >> d >> k;
    if(d>=k) cout << d-k << endl;
    else cout << n+(d-k) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

