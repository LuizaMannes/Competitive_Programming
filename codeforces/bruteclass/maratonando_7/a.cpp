#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    vector<int> ar(n); for(auto &i:ar) cin >> i;

    for(int i=0;i<n;i++) if(ar[i]==1) ar[i]++;

    for(int i=1;i<n;i++){
        if(ar[i]%ar[i-1]==0) ar[i]++; 
    }

    for(auto a:ar) cout << a << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

