#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

const int INF=1e9;
const int maxtemp = 86400; //864005
//const int maxtemp = 1e3; //864005
const int maxn = 10;
int n;
vector<tuple<int,int,int>> ar[maxtemp + 5];
int dp[maxtemp + 5][(1<<maxn)];


void solve() {
    cin >> n;
    for(int i=0;i<n;i++){
        int m; cin >> m;
        for(int j=0;j<m;j++){
            int l,r,val; cin >> l >> r >> val;
            ar[l].emplace_back(i,r,val);
        }
    }

    memset(dp,-1,sizeof dp);
    
    dp[0][0] = 0;
    for(int i = 0; i < maxtemp; i++){
        for(int k=0;k<=(1<<n)-1;k++){
            dp[i+1][k]=max(dp[i][k],dp[i+1][k]);
        }
        for(auto [j, t, val] : ar[i]){
            for(int k=0;k<=(1<<n)-1;k++){ 
                if(dp[i][k]==-1) continue;
                dp[t][k|(1<<j)] = max(dp[t][k|(1<<j)], dp[i][k] + val);
            }
        } 
    }
    
    cout << dp[maxtemp][(1<<n)-1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


