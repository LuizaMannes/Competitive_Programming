#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<int> ar(n);
    int l = 0, res = 0;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        int r = (!i ? x: (a * ar[i - 1] + b) % c);
        ar[i] = r;
        while(dq.size() and dq.back() > r) dq.pop_back();
        dq.emplace_back(r);
        if(i - l + 1 < k) continue;
        res ^= dq.front();
        if(dq.front() == ar[l]) dq.pop_front();
        l++;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

