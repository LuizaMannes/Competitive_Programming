#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod=1e9+7;

int exp(int a, int b){
    int res=1;
    a%=mod;
    while(b){
        if(b & 1) res=(res*a)%mod;
        b >>= 1;
        a=(a*a)%mod;
    }
    return res%mod;
}

void solve() {
    int a,b; cin >> a >> b;
    cout << exp(a,b) << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

