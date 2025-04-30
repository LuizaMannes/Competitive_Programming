#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;cin >> n;
    vector<int> ar(n); 
    
    int res=0;
    for(int i=0;i<n;i++) cin >> ar[i];
    sort(ar.begin(),ar.end());
    if(ar[n-1]*ar[n-2]>ar[0]*ar[1]){
        res=ar[n-1]*ar[n-2];
    }else {
        res=ar[0]*ar[1];
    }
    cout << res << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){     
        solve();
    }
}

