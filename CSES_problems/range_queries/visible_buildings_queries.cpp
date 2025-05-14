#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
const int L = 20;

int up[mx][L];

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<int> b;
    for(int i = 0; i < n - 1; i++){
        b.push_back(i);
        if(ar[i] < ar[i + 1]){
            while(b.size() && ar[b.back()] < ar[i + 1]){
                up[b.back()][0] = i + 1;
                b.pop_back();
            }
        }
    }
    b.push_back(n - 1);

    for(auto i: b) up[i][0] = n;

    for(int i = 0; i < L - 1; i++){
        for(int u = 0; u < n; u++){
            up[u][i + 1] = up[up[u][i]][i];
            if(up[u][i + 1] == 0) up[u][i + 1] = n;
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--;
        b--;

        int res = 1;
        for(int i = L - 1; i >= 0; i--){
            if(up[a][i] <= b){
                a = up[a][i];
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

