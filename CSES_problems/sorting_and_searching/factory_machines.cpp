#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, t; cin >> n >> t;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, r = 1e18 + 9, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;

        int s = 0;
        for(int i = 0; i < n; i++){
            s += mid / ar[i];
            if(s >= t) break;
        }

        if(s >= t){
            res = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

