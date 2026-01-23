#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e6 + 6;
vector<int> dp(mx, 1);

void calc(){
    int lm = 2000;
    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i <= lm; i++){
        set<int> s;
        for(int j = 1; j * 2 < i; j++){
            s.emplace(dp[j] ^ dp[i - j]);
        }
        
        int mex = 0;
        for(auto v: s) if(mex == v) mex++;
        dp[i] = mex;
    }
}

void solve() {
    int n; cin >> n;
    
    cout << (dp[n] ? "first" : "second") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    calc();
    int tc;cin >> tc; while(tc--) solve();
}

