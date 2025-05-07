#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x; cin >> n >> x;

    vector<int> ar(n), pref(n + 1);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        pref[i + 1] = pref[i] + ar[i];
    }

    int i = 1, j = 1, res = 0;
    while(i <= n && j <= n){
        if(pref[j] - pref[i - 1] < x) j++;
        if(pref[j] - pref[i - 1] > x) i++;
        if(pref[j] - pref[i - 1] == x){
            res++;
            j++;
            i++;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

