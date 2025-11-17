#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n; 

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 2;; i++){
        for(int j = 0; j < n; j++){
            if(gcd(i, ar[j]) == 1){
                cout << i << endl;
                return;
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

