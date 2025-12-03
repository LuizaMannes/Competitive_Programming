#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    if(ar[0] == -1 and ar[n - 1] != -1) ar[0] = ar[n - 1]; 
    else if(ar[0] != -1 and ar[n - 1] == -1) ar[n - 1] = ar[0];

    for(int i = 0; i < n; i++) if(ar[i] == -1) ar[i] = 0;
    
    int sum = 0;
    for(int i = 1; i < n; i++){
        sum += ar[i] - ar[i - 1];
    }

    if(sum < 0) sum = -sum;
    cout << sum << endl;
    for(int i = 0; i < n; i++){
        cout << ar[i] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

