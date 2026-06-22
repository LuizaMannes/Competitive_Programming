#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') c1++;
        else c2++;
    }

    if(c1 == c2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

