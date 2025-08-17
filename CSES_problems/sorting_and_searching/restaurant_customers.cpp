#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    vector<pair<int,int>> fila;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        fila.push_back({a, 1});
        fila.push_back({b, -1});
    }

    sort(fila.begin(), fila.end());

    int total = 0, res = 0;
    for(int i = 0; i < fila.size(); i++){
        total += fila[i].second;
        res = max(res, total);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

