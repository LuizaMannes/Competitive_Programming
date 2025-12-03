#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    int ar[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
        }
    }

    vector<bitset<2001>> res(n);
    vector<bitset<2001>> f(1000);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res[j] ^= f[ar[j][i]];
            f[ar[j][i]].set(j);
        }

        for(int j = 0; j < 1000; j++){
            f[j].reset();
        }
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        c += res[i].count();
    }

    cout << c << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

