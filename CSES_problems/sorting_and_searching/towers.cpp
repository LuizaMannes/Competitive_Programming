#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    const int inf = 1e9 + 1;
    vector<int> t(n, inf);
    int res = 0;
    for(int i = 0; i < n; i++){
        int a = upper_bound(t.begin(), t.end(), ar[i]) - t.begin();
        
        if(t[a] == inf) res++;
        t[a] = ar[i]; 
    }   

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

