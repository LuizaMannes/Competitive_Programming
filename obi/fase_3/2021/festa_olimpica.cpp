#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e4+100;

void solve() {
    int n,m;cin >> n >> m;

    vector<int> ar(m);
    vector<int> res(mx);
    for(int i = 0; i < mx; i++){
        res[i] = i;
    }

    for(int i = 0; i < m; i++){
        cin >> ar[i];
    }

    for(int i = m-1; i >=0; i--){
        for(int j = 0; j < min(n, mx); j++){
            if(res[j] >= n) break;

            res[j] += res[j] / (ar[i] - 1);
        }
    }

    for(int i = 0; i < min(n, (int) 10000); i++){
        if(res[i] >= n) break;
        cout << res[i] + 1 << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

