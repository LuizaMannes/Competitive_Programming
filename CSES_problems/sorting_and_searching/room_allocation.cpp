#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using t = tuple<int,int,int>;

const int inf = 1e9 + 1;

void solve() {
    int n; cin >> n;

    vector<t> l;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        l.push_back({a, b, i});
        l.push_back({b, inf, i});
    }

    sort(l.begin(), l.end());

    int res = 0, cont = 0;
    vector<int> ar(n);
    set<int> s;
    for(int i = 0; i < n; i++) s.emplace(i + 1);

    for(auto [a, b, c]: l){
        if(b == inf){
            cont--;
            s.emplace(ar[c]);
        }
        else{
            cont++;
            ar[c] = *s.begin();
            s.erase(s.begin());
            res = max(res, cont);
        }
    }

    cout << res << endl;
    for(int i = 0; i < n; i++) cout << ar[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

