#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> pref(n + 1, 0);
    for(int i = 1; i < n + 1; i++){
        int a; cin >> a;
        pref[i] = pref[i - 1] + a;
    }
    int l = 1, r = n, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        
        cout << "? " << (mid - l) + 1 << " ";
        for(int i = l; i <= mid; i++) cout << i << " ";
        cout << endl;
        cout << flush;

        int x; cin >> x;
        if(x == pref[mid] - pref[l - 1]) l = mid + 1;
        else{
            res = mid;
            r = mid - 1;
        }
    }

    cout << "! " << res << endl;
    cout << flush;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

