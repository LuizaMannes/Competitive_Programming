#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string res;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            char a;cin >> a;
            if(a!='.') res.push_back(a);
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

