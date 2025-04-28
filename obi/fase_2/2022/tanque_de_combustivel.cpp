#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    double a,b,c;cin >> a >> b >> c;
    double d=b/a;
    double e=d-c;
    if(e<0){
        cout << "0.0" << endl;
        return;
    }
    cout << fixed << setprecision(1) <<  e << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

