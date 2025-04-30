#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m;cin >> n >> m;
    string s;cin >> s;
    vector<int> ind(m);
    for(int i=0;i<m;i++) cin >> ind[i];
    string c;cin >> c;
    sort(ind.begin(),ind.end());
    ind.erase(unique(ind.begin(),ind.end()),ind.end());
    sort(c.begin(),c.end());
    for(int i=0;i<ind.size();i++){
        s[ind[i]-1]=c[i];
    }
    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

