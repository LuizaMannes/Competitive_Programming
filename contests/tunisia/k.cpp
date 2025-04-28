#include <bits/stdc++.h>
#define T pair<int,int>

using namespace std;
using ll = long long;

vector<vector<int>> num(10, vector<int> (7));
vector<vector<T>> dif(10, vector<T> (10));
bool dp[105][105][105];
string s, t;
int n, x, y;

bool bp(int i, int xi, int yi){
    if(xi < 0 || yi < 0)
        return 0;
    if(dp[i][xi][yi])
        return 0;
    bool flag = 0;
    if(i == n)
        return true;
    
    dp[i][xi][yi] = 1;
    for(int j = 0; j <= 9; j++)
        flag = flag | bp(i+1, xi - (dif[s[i] - '0'][j].first + dif[t[i] - '0'][j].first), yi - (dif[s[i] - '0'][j].second + dif[t[i] - '0'][j].second));
    return flag;
}


void solve() {
    cin >> n >> x >> y;
    cin >> s;
    cin >> t;
    if(bp(0, x, y))
        cout << "YES\n";
    else
        cout << "NO\n";
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= x; j++)
            for(int k = 0; k <= y; k++)
                dp[i][j][k] = 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    num[0] = {1, 0, 1, 1, 1, 1, 1};
    num[1] = {0, 0, 0, 0, 0, 1, 1};
    num[2] = {1, 1, 1, 0, 1, 1, 0};
    num[3] = {1, 1, 1, 0, 0, 1, 1};
    num[4] = {0, 1, 0, 1, 0, 1, 1};
    num[5] = {1, 1, 1, 1, 0, 0, 1};
    num[6] = {1, 1, 1, 1, 1, 0, 1};
    num[7] = {1, 0, 0, 0, 0, 1, 1};
    num[8] = {1, 1, 1, 1, 1, 1, 1};
    num[9] = {1, 1, 1, 1, 0, 1, 1};

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 7; k++) {
                if (num[i][k] == 1 && num[j][k] == 0) dif[i][j].second++;
                if (num[i][k] == 0 && num[j][k] == 1) dif[i][j].first++;
            }
        }
    }

    int t; cin >> t;
    while (t--) solve();
}
