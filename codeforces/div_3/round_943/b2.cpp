#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m; cin >> n >> m;
    string s,t; cin >> s >> t;
    int j=0;
    int res=0;
    for(int i=0;i<m;i++){
        if(t[i]==s[j] && j<n){
            res++;
            j++;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

