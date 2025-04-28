#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
const int L = 20;

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    int st[L][n + 1];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        st[0][i] = ar[i];
    }

    vector<int> lg(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    for(int i = 0; i < L - 1; i++){
        for(int j = 0; j + (1 << i) < n; j++){
            st[i + 1][j] = min(st[i][j], st[i][j + (1 << i)]);
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;
        int i = lg[b - a + 1];
        cout << min(st[i][a], st[i][b - (1 << i) + 1]) << endl;
    } 
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

