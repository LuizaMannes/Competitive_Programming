#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,x,y;cin >> n >> x >> y;
    int ini = 1 << (n-1);
    int maximo= 1 << n;

    int ans=0;
    while(x!=ini && y!=ini){
        x*=2;
        y*=2;

        if(x>maximo) x-=maximo;
        if(y>maximo) y-=maximo;
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

