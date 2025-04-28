#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    for(int i=0;i<8;i++){
        int a;cin >> a;
        if(a==9){
            cout << "F" << endl;
            return;
        }
    }

    cout << "S" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

