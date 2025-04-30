#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n), ar2(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    int b; cin >> b;

    for(int i = 0; i < n; i++){
        ar2[i] = b - ar[i];
    }

    for(int i = 0; i < n; i++){
        if(ar2[i] < ar[i]){
            if(i != 0 && ar2[i] >= ar[i - 1]) ar[i] = ar2[i];
            if(i == 0) ar[i] = ar2[i];
        }
        if(ar2[i] > ar[i]){
            if(i != 0 && ar[i] < ar[i - 1]) ar[i] = ar2[i];
        }
    }

    bool ok = 1;
    for(int i = 1; i < n; i++){
        if(ar[i] < ar[i - 1]) ok = 0;
    }

    cout << (ok ? "YES": "NO") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

