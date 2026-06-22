#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n + 2);
    for(int i = 1; i <= n; i++) cin >> ar[i];

    vector<int> e(m);
    for(int i = 0; i < m; i++){
        cin >> e[i];
    }
    ar[0] = ar[n + 1] = ar[e[0]];
    e.push_back(n + 1);

    vector<int> g;
    int s = 0, j = 0;
    for(int i = 0; i <= n; i++){
        if(e[j] == i){
            j++;
            g.push_back(s);
            s = 0;
        }
        if(ar[i] != ar[i + 1]) s++;
    }
    g.push_back(s);

    sort(g.begin(), g.end());

    int sum = 0;
    for(int i = 0; i < g.size(); i++) sum += g[i];
    cout << max(g.back(), (int) sum / 2) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

