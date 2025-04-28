#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<vector<int>> ar(n, vector<int> (n)), pref(n + 1, vector<int> (n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a; cin >> a;
            if(a == '*') ar[i][j] = 1;
            pref[i + 1][j + 1] = ar[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
        }
    }

    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

