#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n + 1);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ar[a] = i;
    }

    int res = 1;
    for(int i = 2; i <= n; i++) if(ar[i - 1] > ar[i]) res++;
    
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

