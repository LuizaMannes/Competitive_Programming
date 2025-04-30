#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    int res=ar[n-1];
    for(int i=n-2;i>=0;i--){
        res=max(ar[i],res+1);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

