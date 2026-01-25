#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 102;
void solve() {
    int n; cin >> n;
    
    int g[mx][mx];
    for(int i = 0; i < mx; i++){
        for(int j = 0; j < mx; j++){
            if(i == 0 or j == 0 or i == j){
                g[i][j] = 1000;
                continue;
            }
            set<int> s;
            for(int k = 1; k < mx; k++){
                if(i - k >= 0) s.emplace(g[i - k][j]);

                if(j - k >= 0) s.emplace(g[i][j - k]);

                if(i - k >= 0 and j - k >= 0) s.emplace(g[i - k][j - k]);
            }
            int mex = 0;
            for(auto a : s){
                if(mex == a) mex++;
            }
            g[i][j] = mex;
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        res ^= g[a][b];
    }

    cout << (res ? "Y" : "N") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

