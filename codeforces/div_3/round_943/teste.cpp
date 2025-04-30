#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x,y;cin >> x >> y;
    int a=gcd(x,y)+y;
    cout << a << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

