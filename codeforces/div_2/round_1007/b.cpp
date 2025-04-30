#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n + 2);

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;

        int a = sqrt(sum);
        if(a * a == sum){
            ar[i] = i + 1;
            ar[i + 1] = i;
        }
        
        if(!ar[i]) ar[i] = i;
    }

    if(ar[n] == n + 1) cout << -1;
    else for(int i = 1; i <= n; i++) cout << ar[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

