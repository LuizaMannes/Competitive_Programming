#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);

    for(int i = 0; i < n; i++) cin >> ar[i];

    for(int i = 1; i < n; i++){
        if(abs(ar[i] - ar[i-1]) != 7 && abs(ar[i] - ar[i-1]) != 5){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES"<< endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

