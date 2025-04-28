#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int me=0, pe=0;
    for(int i=0;i<n;i++){
        int t; cin >> t;
        if(t==1) pe++;
        else me++;
    }
    int p; cin >> p;
    int m; cin >> m;
    if(pe-p<0 || me-m<0) cout << "N" << endl;
    else cout << "S" << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

