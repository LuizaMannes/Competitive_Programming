#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    map<char, int> f, g;
    for(int i = 0; i < n; i++) f[s[i]]++;

    for(int i = 0; i < n; i++) g[t[i]]++;

    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(f[s[i]] != g[s[i]]) ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

