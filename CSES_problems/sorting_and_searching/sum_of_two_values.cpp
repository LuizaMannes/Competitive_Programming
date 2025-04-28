#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m; cin >> n >> m;
    vector<int> ar(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        if(mp[m-ar[i]]>0){
            cout << mp[m-ar[i]] << " " << i << endl;
            return;
        }
        mp[ar[i]]=i;
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

