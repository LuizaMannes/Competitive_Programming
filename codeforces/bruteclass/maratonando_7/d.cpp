#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    
    vector<int> ar(n); 
    for(auto &i : ar) cin >> i;
    
    sort(ar.begin(),ar.end());

    cout << ar[n-1]-ar[0]+ar[n-2]-ar[1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}
