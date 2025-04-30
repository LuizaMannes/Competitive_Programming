#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int res=0;
    int aux=0;
    for(int i=1;i<=n;i++){
        int a,b; cin >> a >> b;
        if(a<=10){
            if(aux<b){
                aux=b;
                res=i;
            }
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

