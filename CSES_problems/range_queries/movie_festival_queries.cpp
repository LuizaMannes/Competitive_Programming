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

    for(int i = 1; i < mx; i++){
        for(int j = 0; j < L - 1; j++){
            up[i][j + 1] = up[up[i][j]][j];
        }
    }

    while(q--){
        int a, b; cin >> a >> b;

        int res = 0; 
        while(b){
            int ind = -1;

            for(int i = 0; i < L; i++){
                if(up[b][i] >= a) ind = i;
            }

            if(ind == -1) break;

            res += (1 << ind);
            b = up[b][ind];
        }
        cout << res << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

