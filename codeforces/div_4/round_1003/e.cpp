#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m, k; cin >> n >> m >> k;

    if(max(n - m, m - n) > k){
        cout << -1 << endl;
        return;
    }

    if(k > n && k > m){
        cout << -1 << endl;
        return;
    }

    int a = n + m;
    int b = (m > n);
    for(int i = 1; i <= a; i++){
        if(b) m--;
        else n--;
        
        cout << b;
        if(!n || !m) break;
    
        if(i % k == 0) b = !b;    
    }

    while(n--) cout << 0;
    while(m--) cout << 1;

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

