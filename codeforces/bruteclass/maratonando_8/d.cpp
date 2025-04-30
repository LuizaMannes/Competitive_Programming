#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod=1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    sort(b.begin(), b.end());
    sort(a.begin(),a.end());
    int j=0;
    int res=1;
    for(int i=0;i<n;i++){
        while(j<n && a[i] > b[j]) j++;
        res=res*(j-i)%mod;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

