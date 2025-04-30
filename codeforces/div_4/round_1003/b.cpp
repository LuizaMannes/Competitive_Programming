#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s;cin >> s;
    int res = s.size();

    for(int i = s.size() - 1; i >= 1; i--){
        if(s[i] == s[i - 1]) res = 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

