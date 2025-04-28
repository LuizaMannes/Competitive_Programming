#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;cin >> n >> k;
    vector<int> ar(n+1);
    vector<int> pref(n+1);
    for(int i=1;i<=n;i++) cin >> ar[i];
    pref[1]=ar[1];
    for(int i=2;i<=n;i++) pref[i]=ar[i]+pref[i-1];

    int res=0;
    for(int i=1;i<=n;i++){
        auto aux=upper_bound(pref.begin()+i,pref.end(),pref[i-1]+k)-lower_bound(pref.begin()+i,pref.end(),pref[i-1]+k);
        res+=aux;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

