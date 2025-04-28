#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s; cin >> s;
    int m;cin >> m;
    string t;cin >> t;
    int res=0;
    for(int i=0;i<min(n,m);i++){
        if(s[i]!=t[i]) break;
        res++;
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

