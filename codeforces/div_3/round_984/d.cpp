#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    string t = "1543";

    vector<string> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int res = 0;
    for(int i = 0; i < min(n, m) / 2; i++){
        string s;
        
        int j = i, k = i;

        while(j + 1 < m - i){
            j++;
            s += ar[k][j];
        }
        
        while(k + 1 < n - i){
            k++;
            s += ar[k][j];
        }

        while(j - 1 >= i){
            j--;
            s += ar[k][j];
        }

        while(k - 1 >= i){
            k--;
            s += ar[k][j];
        }

        s += s[0];
        s += s[1];
        s += s[2];

        for(int l = 0; l < s.size(); l++){
            if(s.substr(l, 4) == t) res++;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

