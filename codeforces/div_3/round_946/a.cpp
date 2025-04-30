#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    long double x,y; cin >> x >>y;
    long double res = ceil(y/2);
    long double b = y*4;
    if(y==0) res=ceil(x/15);
    if(x>15*res-b) {
        res+=ceil((x-(15*res-b))/15);
    }
    cout << res << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

