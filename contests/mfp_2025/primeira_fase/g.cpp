#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    string r1, r2;

    for(int i = 1; i <= s.size(); i++){
        if(i & 1){
            r1.push_back(s[i-1]);
        }else{
            r2.push_back(s[i-1]);
        }
    }

    cout << r1 << endl;
    cout << r2 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

