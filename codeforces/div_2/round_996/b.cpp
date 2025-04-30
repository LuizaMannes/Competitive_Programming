#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n), q(n), p(n);

    for(int i = 0; i < n ; i++) cin >> ar[i];
    for(int i = 0; i < n ; i++) cin >> q[i];

    int o = 0;
    for(int i = 0; i < n; i++){
        if(ar[i] < q[i]){
            p[i] = q[i] - ar[i];
            o += p[i];
        }else p[i] = 0;
    }

    for(int i = 0; i < n; i++){
        p[i] = ar[i] - o + p[i] * 2;
        //p[i] = max(0ll, a);
        if(p[i] < q[i]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

