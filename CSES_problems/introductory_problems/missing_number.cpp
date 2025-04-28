#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    for(int i=1;i<n;i++){
        cin >> ar[i];
    }
    int res=0;
    for(int i=1;i<n;i++){
        res^=ar[i];
        res^=i;
    }
    res^=n;
    cout << res << endl;
    

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

