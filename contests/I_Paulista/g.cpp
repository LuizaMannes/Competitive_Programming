#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;

    if(s[0] == '?' || s[1] == '?' || s[2] == '?'){
        if(s[3] == 'S' && s[4] == 'P') cout << "S" << endl;
        else cout << "N" << endl;
    }

    if(s[3] == '?'){
        if(s[4] == 'P') cout << "T" << endl;
        else cout << "N" << endl;
    }

    if(s[4] == '?'){
        if(s[3] == 'S') cout << "T" << endl;
        else cout << "N" << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

