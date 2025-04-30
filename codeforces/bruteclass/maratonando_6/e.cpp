#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    
    vector<int> a(n); for(int &i : a) cin >> i;

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int N=a.size();
    int j=0;
    int res=0;
    for(int i=0;i<N;i++){
        while(j < N && a[j]-a[i] < n) j++;

        res=max(res,j-i);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

