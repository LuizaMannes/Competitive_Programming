#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> ar(n, vector<int> (m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> ar[i][j];
    }

    int a = n * m;
    vector<pair<int,int>> s(n);
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += ar[i][j];
        }
        s[i].first = sum;
        s[i].second = i;
    }

    sort(s.rbegin(),s.rend());
    vector<int> sar;
    for(auto [sum, i]: s){
        for(int j = 0; j < m; j++) sar.push_back(ar[i][j]);
    }

    int res = 0;
    for(int i = 0; i < n * m; i++) res += sar[i] * (a - i);

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

