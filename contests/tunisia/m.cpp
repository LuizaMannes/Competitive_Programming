#include <bits/stdc++.h>
#define int long long

using namespace std;
//using ll = long long;
const int maxr = 1e6;

int sum(int n){
    return (n * (n+1))/2;
}

void solve() {
    int x; cin >> x;
    int X = x;
    int need = 1;
    while(x % 2 == 0){
        x /= 2;
        need *= 2;
    }
    int l = x/2, r = x/2 + 1;
    need--;
    if(need){
        l -= min(need, x/2 - 1);
        r += min(need, x/2 - 1);
        need -= min(need, x/2 - 1);
    }
    if(need){
        r++;
        need--;
    }
    if(need){
        r += need;
        l += need;
    }
    if(r < X)
        cout << l << ' ' << r << '\n';
    else
        cout << "-1\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int t; cin >> t;
    while (t--) solve();
}