#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    int fp = 0, fi = 0;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        if(ar[i] & 1) fi++;
        else fp++;
    }

    if(fp and fi) sort(ar.begin(), ar.end());

    for(int i = 0; i < n; i++) cout << ar[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

