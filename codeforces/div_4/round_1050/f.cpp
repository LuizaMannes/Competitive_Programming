#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar[n];
    int mx = 0;
    set<int> s;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        s.emplace(i);
        mx = max(mx, m);
        for(int j = 0; j < m; j++){
            int a; cin >> a;
            ar[i].push_back(a);
        }
    }

    vector<int> res;
    for(int i = 0; i < mx; i++){
        int ok = s.size() == 0;
        for(auto j: s){
            if(ar[j].size() <= i) {
                ok = 1;
                break;
            }
        }

        if(ok) for(int j = 0; j < n; j++) s.emplace(j);

        int mn = 1e9;
        set<int> t;
        for(auto j: s){
            if(ar[j].size() <= i) {
                continue;
            }
            mn = min(mn, ar[j][i]);
        }

        for(auto j: s){
            if(ar[j].size() <= i) {
                continue;
            }
            if(ar[j][i] == mn) t.emplace(j);
        }

        res.push_back(mn);
        swap(s,t);
    }

    for(auto a: res) cout << a << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

