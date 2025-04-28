#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

//    |o_o|

const int INF=1e18;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<pair<int,int>> mcqueen(n);
    vector<int> dp(n+1,-INF);
    for(int i=0;i<n;i++) cin >> mcqueen[i].first >> mcqueen[i].second;
    
    dp[0]=0;

    for(int i=0;i<n;i++){
        dp[i+1]=max(dp[i+1],dp[i]-mcqueen[i].first+mcqueen[i].second);
        if(i+k<=n){
            dp[i+k]=max(dp[i+k],dp[i]-x);
        }else{
            dp[n]=max(dp[n],dp[i]-x);
        }
    }
    if(dp[n]<0) cout << 0 << endl;
    else cout << dp[n] << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

