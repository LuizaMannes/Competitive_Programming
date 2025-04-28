#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    double l,c; cin >> l >> c;
    double aux=l*c;
    double outro=aux/0.5;
    outro--;
    l--;
    c--;
    outro-=l;
    outro-=c;
    cout << outro << endl;
    double a=0;
    a=(l+c)*2;
    cout << a << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

