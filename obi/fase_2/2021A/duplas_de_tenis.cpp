#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    vector<int> ar(4);
    cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];

    sort(ar.begin(),ar.end());

    int a = ar[0] + ar[3];
    int b = ar[1] + ar[2];

    if(a<b) swap(a,b);

    cout << a - b << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
