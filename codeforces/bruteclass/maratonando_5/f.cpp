#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> v(n), v2;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        v2.push_back(v[i]);

    }

    sort(v2.begin(), v2.end());

    for(int i = 0; i < n; i++){
        if(v[i] == v2[n-1]){
            cout << v[i] - v2[n-2] << ' ';
        }
        else{
            cout << v[i] - v2[n-1] << ' ';
        }
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

