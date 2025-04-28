#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MOD=1e9+7;

int exp(int a, int b,int mod){
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
    int a,b,c; cin >> a >> b >> c;
    int d=exp(b,c,MOD-1);
    cout << exp(a,d,MOD) << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}


