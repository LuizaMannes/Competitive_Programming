#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n + 1), adj[n + 1];
    
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> res(n + 1); 
    for(int i = 1; i <= n; i++){
        map<int,int> f;
        f[ar[i]]++;
        for(auto u: adj[i]){
            f[ar[u]]++;
            if(f[ar[u]] >= 2) res[ar[u]] = 1;
        }
       
    }

    for(int i = 1; i <= n; i++){
        cout << res[i];
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

