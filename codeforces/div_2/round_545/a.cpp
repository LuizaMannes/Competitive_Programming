#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int cur = 1, last = 0, res = 0; 
    for(int i = 0; i < n - 1; i++){
        if(ar[i + 1] != ar[i]){
            res = max(res, min(last,cur) * 2);
            last = cur;
            cur = 1;
        } else cur++;
    }
    res = max(res, min(last,cur) * 2);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

