#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;cin >> n;
   
    vector<int> x(n-1);
    for(int i=0;i<n-1;i++) cin >> x[i];
    
    vector<int> res={501};
    
    for(int i=0;i<n-1;i++){
        res.push_back(res[i]+x[i]);
    }
    
    for(auto c:res) cout << c << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        solve();
    }
}

