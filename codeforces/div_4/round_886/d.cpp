#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;cin >> n >> k;
    vector<int> ar(n);

    for(int i=0;i<n;i++) cin >> ar[i];
    sort(ar.begin(),ar.end());

    int count=0;
    int res=0;
    for(int i=0;i<n-1;i++){
        count++;
        if(ar[i+1]-ar[i]>k){
            res=max(res,count);
            count = 0;
        }
    }
    count++;
    res=max(res,count);
    cout << n-res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

