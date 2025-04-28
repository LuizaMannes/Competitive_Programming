#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int cont = 0;
    while(n != 0){
        if(n&1) cont++;
        n /= 2;
    }

    int ans = pow(2, cont);
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

