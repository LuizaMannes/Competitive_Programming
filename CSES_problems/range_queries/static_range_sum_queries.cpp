#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    vector<int> pre(n+1);

    for(int i = 0; i < n; i++){
        cin >> ar[i];
        pre[i+1] = pre[i] + ar[i];
    }

    while(q--){
        int a, b; cin >> a >> b;

        cout << pre[b] - pre[a-1] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

