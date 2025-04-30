#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a,b,c; cin >> a >> b >> c;
    if(a+b>=10 || a+c>=10 || b+c>=10) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

