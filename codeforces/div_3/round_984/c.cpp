#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    string t = "1100";

    int n = s.size();
    int r = 0;

    for(int i = 0; i < n - 3; i++) if(s.substr(i,4) == t) r++;

    int q; cin >> q;
    while(q--){
        int i; cin >> i;
        i--; 
        char v; cin >> v;
        
        for(int j = max((int)0 , i - 3); j <= i; j++){
            if(s.substr(j,4) == t) r--;
        }

        s[i] = v;

        for(int j = max((int)0 , i - 3); j <= i; j++){
            if(s.substr(j,4) == t) r++;
        }

        cout << (r ? "YES" : "NO") << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

