#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int res = 0;
    map<int,int> m;
    int j = 0;
    for(int i = 0; i < n; i++){
        m[ar[i]]++;
        while(m[ar[i]] > 1) {
            m[ar[j]]--;
            j++;
        }

        res = max(res, i - j + 1);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

