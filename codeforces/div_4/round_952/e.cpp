#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int x,y,z,k; cin >> x >> y >> z >> k;
    vector<tuple<int,int,int>> cord;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            int aux=i*j;
            if(k%aux==0) cord.emplace_back(i,j,k/aux);
        } 
    }
    int res=0;
    for(auto [a,b,c]:cord){
        int a1=x-a+1;
        int b1=y-b+1;
        int c1=z-c+1;
        int mult=a1*b1*c1;
        if(mult<0) continue;
        res=max(res,mult);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

