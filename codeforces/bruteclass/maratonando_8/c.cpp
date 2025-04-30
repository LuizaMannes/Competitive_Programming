#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    int res=0;
    for(int i=0;i<n;i++) cin >> ar[i];
    
    for(int i=0;i<n;i++){
        int a=abs(ar[i]-i-1);
        res=gcd(res,a);
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

