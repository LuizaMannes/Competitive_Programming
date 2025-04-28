#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    cout << n << " ";
    while(n!=1){
        if(n&1) {
            n=n*3+1;
            cout << n << " ";
        }
        else{
            n/=2;
            cout << n << " ";
        }
    }
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

