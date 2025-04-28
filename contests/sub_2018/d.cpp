#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    int ans = 0;
    while(n--){
        int x; cin >> x;
        if(x != 1) ans++;
    }
    
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

