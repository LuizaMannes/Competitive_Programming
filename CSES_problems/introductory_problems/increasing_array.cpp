#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);

    for(auto &i:ar) cin >> i;

    int res=0;
    for(int i=1;i<n;i++){
        if(ar[i]<ar[i-1]){
            res+=ar[i-1]-ar[i];
            ar[i]=ar[i-1];
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

