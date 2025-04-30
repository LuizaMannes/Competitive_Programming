#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    map<int,int> mp;
    vector<int> f;

    int res = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(!mp[a]) res++;
        mp[a]++;
    }
    
    for(auto [a, b]: mp) f.push_back(b);

    sort(f.begin(), f.end());

    int j = 0;
    while(k--){
        f[j]--;
        if(f[j] == 0){
            res--;
            j++;
        }
    }

    cout << max(res, 1ll) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

