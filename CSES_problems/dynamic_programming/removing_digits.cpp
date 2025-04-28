#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1, INF);
    
    dp[n] = 0;
    for(int i = n; i >= 0; i--){
        int aux = i;
        while(aux){
            int a = aux % 10;
            if(i - a < 0) continue;
            dp[i - a] = min(dp[i - a], dp[i] + 1);
            aux /= 10;
        }
    }

    //for(int i = 0; i <= n; i++) cout << dp[i] << " ";
    //cout << endl;
    cout << dp[0] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

