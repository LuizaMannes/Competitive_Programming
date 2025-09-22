#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int x, n; cin >> x >> n;

    set<int> s;
    multiset<int> ms;
    s.insert(0);
    s.insert(x);
    ms.insert(x);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        auto l = s.upper_bound(a);
        auto r = l;
        l--;
        auto ind = ms.lower_bound(*r - *l);

        ms.erase(ind);
        ms.insert(a - *l);
        ms.insert(*r - a);
        s.insert(a);

        cout << *ms.rbegin() << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

