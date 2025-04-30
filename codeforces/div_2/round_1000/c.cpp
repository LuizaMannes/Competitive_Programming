#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx];

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> cont(n + 1);
    map<int,int> in, a;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;

        cont[a].first++;
        cont[b].first++;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i <= n; i++) cont[i].second = i;
    
    sort(cont.rbegin(),cont.rend());
    for(int i = 0; i <= n; i++) in[cont[i].second] = i;
    

    int m1 = cont[0].second, m2 = cont[1].second;

    int res = 0;
    for(auto v: adj[m1]){
        cont[in[v]].first--;
        a[v] = 1;
    }

    sort(cont.rbegin(),cont.rend());
    for(int i = 0; i <= n; i++) in[cont[i].second] = i;
    
    res = cont[0].first + cont[1].first;

    for(auto [d,c]: a) cont[in[d]].first++;
    
    for(auto v: adj[m2]){
        cont[in[v]].first--;
    }

    sort(cont.rbegin(),cont.rend());

    res = max(res, cont[0].first + cont[1].first);

    cout << res - 1 << endl;

    for(int i = 0; i <= n; i++){
        adj[i].clear();
    }
}   

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

