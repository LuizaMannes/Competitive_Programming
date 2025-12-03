#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;

    int b = 0, res = 0;
    map<int,int> f;
    f[0] = 1;
    for(int i = 0; i < s.size(); i++){
        b ^= 1 << (s[i] - '0');
        res += f[b];
        f[b]++;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

