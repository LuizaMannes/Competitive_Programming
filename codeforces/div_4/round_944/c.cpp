#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int a,b,c,d; cin >> a >> b >> c >> d;
    vector<int> m;
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);
    sort(m.begin(),m.end());
    if((m[0]==a && m[2]==b )|| (m[0]==b && m[2]==a )||( m[1]==a && m[3]==b )||( m[1]==b && m[3]==a)){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

