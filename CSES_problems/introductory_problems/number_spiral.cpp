#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int l, c; cin >> l >> c;
    
    int res = 2 * (max(l, c) - 1) - 1;
    res = (1 + res) * (max(l, c) - 1) / 2;

    if(l >= c){
        if(l & 1) res++;
        else res += 2 * l - 1;
    
        res += (c - 1) * (l & 1 ? 1 : -1);
    }else{
        if(c & 1) res += 2 * c - 1;
        else res++;
        
        res += (l - 1) * (c & 1 ? -1 : 1);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

