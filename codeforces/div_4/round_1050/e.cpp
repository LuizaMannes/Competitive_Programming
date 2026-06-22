#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
const int mx = 2e5 + 5;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(n);
    vector<int> f(mx);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        f[ar[i]]++;
    }

    for(int i = 1; i < mx; i++){
        if(f[i] % k != 0) {
            cout << 0 << endl;
            return;
        } 
    }

    int l = 0, r = 0, res = 0;
    vector<int> f2(mx);
    while(l < n){
        while(r < n and f2[ar[r]] < f[ar[r]] / k){
            f2[ar[r]]++;
            res += r - l + 1;
            r++;
        }
        f2[ar[l]]--;
        l++;
    }

    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

