#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    sort(ar.rbegin(), ar.rend());

    int a = ar[0], b = 0;
    for(int i = 1; i < n; i++){
        if(i & 1) {
            int diff = ar[i - 1] - ar[i];
            if(diff <= k){
                ar[i] += diff;
                k -= diff;
            }else{
                ar[i] += k;
                k = 0;
            }

            b += ar[i];
        }
        else a += ar[i];
    }

    cout << a - b << endl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

