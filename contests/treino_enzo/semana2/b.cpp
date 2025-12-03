#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;
    vector<int> ar(n + 1);
    vector<vector<int>> as(sqrt(n) + 1, vector<int> (sqrt(n) + 1, 0));
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int a, b, c; cin >> a >> b >> c;
            if(b >= (int)sqrt(n)){
                for(int j = a; j <= n; j+=b) ar[j] += c;
            }else as[b][a%b] += c;
        }else{
            int a; cin >> a;
            int res = ar[a];    

            for(int j = 1; j < sqrt(n); j++){
                res += as[j][a%j];
            }
            cout << res << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

