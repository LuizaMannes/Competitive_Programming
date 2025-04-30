#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;cin >> n >> k;
    map<int,vector<int>> mapa;

    for(int i=0;i<n;i++){
        int a;cin >> a;
        mapa[a%k].emplace_back(a);
    }

    int imp=0;
    int res=0;
    for(auto [m,v]:mapa){
        sort(v.begin(),v.end());
        int s=v.size();

        if(s & 1){
            imp++;
            vector<vector<int>> dp(s+1,vector<int>(2,1e9));
            dp[0][0]=0;
            dp[0][1]=0;
            dp[1][1]=0;

            for(int i=2;i<=s;i++){
                int a=(v[i-1]-v[i-2])/k;
                dp[i][0]=dp[i-2][0]+a;
                dp[i][1]=dp[i-2][0]+a;
                dp[i][1]=min(dp[i-2][1]+a,dp[i-1][0]);
            }
            res+=dp[s][1];
        }else{
            for(int i=1;i<s;i+=2){
                res+=(v[i]-v[i-1])/k;
            }
        }
    }
    cout << (imp>1? -1:res) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

