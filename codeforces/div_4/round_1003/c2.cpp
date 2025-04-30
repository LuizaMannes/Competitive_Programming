#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int bbin(vector<int> ar, int a, int b, int m){
    int l = 0, r = m - 1;
    int res = a;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(ar[mid] - a >= b){
            r = mid - 1;
            res = ar[mid] - a;
        }else l = mid + 1;
    }

    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n), b(m);
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(),b.end());

    if(b[0] - ar[0] < ar[0]) ar[0] = b[0] - ar[0];

    for(int i = 1; i < n; i++){
        int a = bbin(b, ar[i], ar[i - 1], m);
        if(ar[i] < a && ar[i] >= ar[i - 1]) continue;
        if(a < ar[i]) ar[i] = a;
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


