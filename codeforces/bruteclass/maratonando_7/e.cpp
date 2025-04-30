#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m;cin >> n >> m;
    string s;

    for(int i=0;i<m;i++) s.push_back('B');

    for(int i=0;i<n;i++){
        int a;cin >> a;
        int b = m+1-a;
        a--;
        b--;

        if(a>b) swap(a,b);

        if(s[a]!='A') s[a]='A';
        else s[b]='A';
    }

    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

