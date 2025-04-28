#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 105;

bool pode(int i, int j){
    return i < n && j < m && i >=0 && j >= 0;
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
            ar[i][j]++;
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

