#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<string> ar(n);

    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    vector<int> res(n);

    for(int i = 1; i <= n; i++){
        int a = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            
            if(ar[i - 1][j - 1] == '1') a += (i > j);
            else a += (i < j);
        }

        res[a] = i;
    }

    for(auto b : res){
        cout << b << " ";
    }

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

