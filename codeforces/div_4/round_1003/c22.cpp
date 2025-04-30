#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n), b(m);
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(),b.end());

    if(b[0] - ar[0] < ar[0]) ar[0] = b[0] - ar[0];

    for(int i = 1; i < n; i++){
        int l = 0, r = m - 1;
        int res = ar[i];
        while(l <= r){
            int mid = (l + r) >> 1;
            if(b[mid] - ar[i] >= ar[i-1]){
                r = mid - 1;
                res = b[mid] - ar[i];
            }else l = mid + 1;
        }

        if(ar[i] < res && ar[i] >= ar[i - 1]) continue;
        if(res >= ar[i - 1]) ar[i] = res;
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


