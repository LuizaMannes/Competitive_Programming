#include <bits/stdc++.h>

using namespace std;

#define int long long

const int nmax=2e5+10;

vector<int>dp(nmax,-1);

int calc(int a,int b,string &s, string &t){
    if(a==-1 || b==-1) return 0;

    if(dp[a]!=-1) return dp[a];
    
    if(s[a]==t[b]){
        dp[a]=1+calc(a-1,b-1,s,t);
        return dp[a];
    }else {
        dp[a]=calc(a,b-1,s,t);
        return dp[a];
    }
    return dp[a];
}


void solve() {
    int n,m; cin >> n >> m;
    string a, b; cin >> a >> b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){
        dp[i]=-1;
    }
    calc(n-1,m-1,a,b);
    cout << dp[n-1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin>>tc;
    while(tc--){
        solve();
    }
}

