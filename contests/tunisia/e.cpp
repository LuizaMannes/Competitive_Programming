#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> freq(n), res;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        while(k--){
            int a; cin >> a;
            --a;
            freq[a]++;
        }
    }
    for(int i = 0; i < n; i++)
        if(freq[i] > n/2)
            res.emplace_back(i+1);
    cout << res.size() << '\n';
    for(auto x : res)
        cout << x << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int t; cin >> t;
    while (t--) solve();
}