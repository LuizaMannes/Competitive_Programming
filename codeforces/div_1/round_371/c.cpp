#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    priority_queue<int> pq;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ar[i] -= i;
        ans -= ar[i];
        pq.emplace(ar[i]);
        pq.emplace(ar[i]);
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

