#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e3 + 3;

vector<vector<int>> dp(mx, vector<int>(mx, -1));

int lcs(int i, int j, vector<int> &s, vector<int> &t){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        dp[i][j] = lcs(i - 1, j - 1, s, t) + 1;
    }else{
        dp[i][j] = max(lcs(i - 1, j, s, t), lcs(i, j - 1, s, t));
    }

    return dp[i][j];
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> s(n), t(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];

    n--, m--;
    int a = lcs(n, m, s, t);
    cout << a << endl;

    vector<int> res;
    int i = n, j = m;
    while(i >= 0 and j >= 0){
        if(s[i] == t[j]){
            res.push_back(s[i]);
            i--; j--;
        }else{
            if(i == 0) {
                j--;
                continue;
            }
            if(j == 0){
                i--;
                continue;
            }
            if(dp[i][j - 1] > dp[i - 1][j]) j--;
            else i--;
        }
    }

    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

