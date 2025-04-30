#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    vector<int> ar(n); for(int &i: ar) cin >> i;
    
    multiset<int> ms; 
    int res=0;
    for(int i=0;i<n;i++){
        if(ar[i]!=0) ms.emplace(ar[i]);
        else{
            if(!ms.empty()){
                res+=*ms.rbegin();
                ms.erase(--ms.end());
            }
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

