#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    map<int,int> x,y,soma,dif;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        x[a]++;
        y[b]++;
        soma[a+b]++;
        dif[a-b]++;
    }
    int res=0;
    for(auto [a,b]:x) res+=(b-1)*b;
    for(auto [a,b]:y) res+=(b-1)*b;
    for(auto [a,b]:soma) res+=(b-1)*b;
    for(auto [a,b]:dif) res+=(b-1)*b;
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

