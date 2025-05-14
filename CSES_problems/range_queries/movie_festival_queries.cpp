#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e6 + 6;
const int L = 20;
int up[mx][L];

void solve() {
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        up[b][0] = max(up[b][0], a);
    }

    for(int i = 1; i < mx; i++) up[i][0] = max(up[i][0], up[i - 1][0]);

    for(int j = 0; j < L - 1; j++){
        for(int i = 1; i < mx; i++){
            up[i][j + 1] = up[up[i][j]][j];
        }
    }

    while(q--){
        int a, b; cin >> a >> b;

        int res = 0; 
        
        for(int i = L - 1; i >= 0; i--){
            if(up[b][i] >= a){
                b = up[b][i];
                res += (1 << i);
            }
        }

        cout << res << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

