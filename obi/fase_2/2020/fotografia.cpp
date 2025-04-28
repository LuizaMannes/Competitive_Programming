#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF=1e5;

void solve() {
    int a,l,n;cin >> a >> l >> n; 
    int area=a*l;

    int res=-1;
    int dif=INF;
    for(int i=0;i<n;i++){
        int b,c;cin >> b >> c;

        int d=b*c;
        if(d < area) continue;
        if(d-area < dif){
            res=i+1;
            dif=d-area;
        }
    }
    cout << res << endl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
