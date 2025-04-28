#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mx = 1e7+7;
int spf[mx];

void calc() {
    for (int i = 2; i < mx; i++) {
        if (spf[i] != 0) continue;
        else {
            spf[i] = i;
            for (int j = i + i; j < mx; j += i) {
                if (!spf[j]) spf[j] = i;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int y = b[i];
        int cont = 0;
        while (x != y) {
            if (x > y) x /= spf[x];
            else y /= spf[y];
            cont++;
        }
        // cout << "cont = " << cont << endl;
        ans += cont;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);    
    calc();
    int t; cin >> t;
    while (t--) solve();
}