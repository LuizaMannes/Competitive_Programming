#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m,c; cin >> n >> m >> c;
    map<int,int> mapa;
    int evil=c;
    for(int i=0;i<n;i++){
        int a, d; cin >> a >> d;
        if(mapa[d]==0) mapa[d]=a;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(mapa[evil]!=0){
            res++;
            evil=mapa[evil];
        }
    }
    if(res<n) cout << res << endl;
    else cout << -1 << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

