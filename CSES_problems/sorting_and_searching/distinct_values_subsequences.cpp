#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    map<int,int> f;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        f[ar[i]]++;
    }

    sort(ar.begin(), ar.end());
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    int res = 0;
    vector<int> pref(ar.size() + 1);
    for(int i = 0; i < ar.size(); i++){
        int a = (f[ar[i]] * (pref[i] + 1)) % mod;

        pref[i + 1] = (pref[i] + a) % mod;
        res = (res + a) % mod;
    }
    
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


