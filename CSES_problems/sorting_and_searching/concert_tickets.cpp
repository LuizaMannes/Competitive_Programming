#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    multiset<int> a;
    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        a.insert(b);
    }

    for(int i = 0; i < m; i++){
        int c; cin >> c;
        auto it = a.upper_bound(c);
        if(it == a.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << *it << endl;
            a.erase(it);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

