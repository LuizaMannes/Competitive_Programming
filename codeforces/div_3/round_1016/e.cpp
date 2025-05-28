#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, r = n, res = 0;
    while(l <= r){
        int mid = (l + r) / 2;

        int cont1 = 0, cont2 = 0;
        vector<int> f(mid + 1);
        for(int i = 0; i < n; i++){
            if(ar[i] < mid && !f[ar[i]]){
                cont1++;
                f[ar[i]]++;
            }
            if(cont1 == mid){
                for(int i = 0; i < mid; i++) f[i] = 0;
                cont2++;
                cont1 = 0;
            }
        }

        if(cont2 >= k){
            res = mid;
            l = mid + 1;
        }else r = mid - 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

