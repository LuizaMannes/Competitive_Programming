#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a, b;cin >> a >> b;

    int ana = a%3;
    int bea = b%3;
    if(bea == ana) bea = (bea+1) %3;
    int ca = bea ^ ana ^ 3;
    cout << ca << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

