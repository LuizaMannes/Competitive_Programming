#include <bits/stdc++.h>

using namespace std;

signed main() {
    int tc; cin >> tc;
    while(tc--){
        int n, x; cin >> n >> x;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            cout << (a < x ? "1 " : "0 ");
        }
        cout << '\n';
    }
}