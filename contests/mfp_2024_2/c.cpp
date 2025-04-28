#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && n - m <= i){
            res = i;
            break;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

