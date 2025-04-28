#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }

    int carlos = a[0];

    sort(a.begin(), a.end());
    if(carlos >= a.back()) cout << "S" << endl;
    else cout << "N" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

