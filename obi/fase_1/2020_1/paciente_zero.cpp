#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n+1);
    set<int> res;
    for(int i=0;i<c;i++){
        int p,m;cin >> p >> m;
        for(int j=0;j<m;j++){
            int k;cin >> k;
            a[k]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) res.emplace(i);
    }
    for(auto c:res) cout << c << endl;
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
