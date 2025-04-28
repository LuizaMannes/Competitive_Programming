#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    cout << setprecision(2) << fixed;
    int t,n;cin >> t >> n;
    vector<int> ar(n);
    
    for(int i=0;i<n;i++) cin >> ar[i];
    sort(ar.begin(),ar.end());

    double res=1000000;
    double now=0;
    for(int i=0;i<n-1;i++){
        double a=((double)ar[i+1]-(double)ar[i])/2+(double) ar[i]-now;
        res=min(res,a);
        now=((double)ar[i]+(double)ar[i+1])/2;
    }
    res=min(res,(double)t-(double)ar[n-1]+(double)ar[n-1]-now);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

