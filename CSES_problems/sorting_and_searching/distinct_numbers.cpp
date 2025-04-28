#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    map<int,int> mp;
    int res=0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(mp[x]==0) res++;
        mp[x]++;
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

