#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n), pref(n + 1);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        pref[i + 1] = ar[i] ^ pref[i];
    }

    while(q--){
        int l, r; cin >> l >> r;

        cout << (pref[r] ^ pref[l - 1]) << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

