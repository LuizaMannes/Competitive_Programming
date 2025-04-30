#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x;cin >> x;
    int ans=0;
    for(int i=1;i<x;i++){
        if(gcd(x,i)+i==x){
            ans=i;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin>>tc;
    while(tc--){
        solve();
    }
}

