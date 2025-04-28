#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    int aux=(n-3)%8;
    if(aux==3) cout << '1' << endl;
    if(aux==4) cout << '2' << endl;
    if(aux==5) cout << '3' << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

