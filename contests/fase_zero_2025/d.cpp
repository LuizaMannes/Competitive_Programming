#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    double colap = 0, sobre = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '*') sobre++;
        if(s[i] == '*' && t[i] != s[i]) colap++;
    }

    cout << setprecision(2) << fixed;
    cout << colap/sobre << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

