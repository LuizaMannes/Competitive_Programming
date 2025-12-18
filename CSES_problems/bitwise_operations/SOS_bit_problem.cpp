#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int LG = 22;
int dp1[1 << LG], dp2[1 << LG], dp3[1 << LG];

void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    int inv = (1 << LG) - 1;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        dp1[ar[i]]++;
        dp2[ar[i]]++;
        dp3[ar[i]  ^ inv]++;
    }

    for(int j = 0; j < LG; j++){
        for(int i = (1 << LG) - 1; i >= 0; i--){
            if((i >> j) & 1){
                dp2[i ^ (1 << j)] += dp2[i];
                dp3[i ^ (1 << j)] += dp3[i];
            }
            if(!((i >> j) & 1)){
                dp1[i ^ (1 << j)] += dp1[i];
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dp1[ar[i]] << " " << dp2[ar[i]] << " " << n - dp3[ar[i]] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

