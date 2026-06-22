#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int atual = 0, last = ar[n - 1];
    for(int i = n - 2; i >= 0; i--){
        int a = max(0ll, ar[i] - last);
        atual += a; 
        last = ar[i] - a;
    }

    int now = ar[n - 1], cont = 0, res = atual;
    for(int i = n - 2; i >= 0; i--){
        if(ar[i] >= now) cont++;
        else{
            res = max(res, atual + cont);
            now = ar[i];
            cont = 0;
        }
    }
    res = max(res, atual + cont);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

