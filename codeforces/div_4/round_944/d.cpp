#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s;cin >> s;
    int mal=s[0]^1;
    int res=1;
    bool pode=true;
    for(int i=0;i<s.size();i++){
        if(mal==49 && pode && s[i]==mal){
            pode=false;
            res--;
        }
        if(s[i]==mal){
            res++;
            mal^=1;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

