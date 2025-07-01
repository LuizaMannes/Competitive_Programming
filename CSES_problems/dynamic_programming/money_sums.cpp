#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    
    vector<int> res;
    for(int i = 0; i < n; i++){
        int m = res.size();
        for(int j = 0; j < m; j++){
            res.push_back(ar[i] + res[j]);
        }
        res.push_back(ar[i]);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

