#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, p, k; cin >> n >> p >> k;

    vector<int> ar(n + 1);

    ar[1] = p;
    for(int i = 2; i <= n; i++){
        ar[i] = ar[i - 1] + 1;
    }

    for(int i = 1; i <= n; i++){
        if(ar[i] > n){
            ar[i] %= n;
        }
    }

    cout << ar[k % (n - 1) + 2] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

