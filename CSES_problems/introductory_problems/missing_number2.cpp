#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    int sum=0;
    for(int i=1;i<n;i++){
        int a; cin >> a;
        sum+=a;
    }

    int total=n*(n+1)/2;
    int res=total-sum;
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

