#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m,p; cin >> n >> m >> p;
    int aux=n-(m+p);
    int res=max(m,p);
    res=max(res,aux);
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

