#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, d; cin >> n >> d;

    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ar[i] = {a, b};
    }

    sort(ar.begin(), ar.end());

    vector<int> dp1(n);
    dp1[0] = ar[0].second;
    int m = dp1[0], ind = 0;
    for(int i = 1; i < n; i++){
        if(ar[i].first - ar[i - 1].first <= d){
            dp1[i] = dp1[i - 1] + ar[i].second;
            if(dp1[i] >= m){
                ind = i;
                m = dp1[i];
            }
        }else{
            dp1[i] = ar[i].second;
            if(dp1[i] >= m){
                ind = i;
                m = dp1[i];
            }
        }
    }

    vector<int> u(n);
    u[ind] = 1;
    for(int i = ind; i > 0; i--){
        if(ar[i].first - ar[i - 1].first <= d) u[i - 1] = 1;
        else break;
    }

    vector<pair<int,int>> ar2;
    int mx1 = 0;
    for(int i = 0; i < n; i++){
        mx1 = max(dp1[i], mx1);
        if(u[i]) continue;
        ar2.push_back(ar[i]);
    }

    vector<int> dp2(ar2.size());
    if(ar2.size()) dp2[0] = ar2[0].second;
    for(int i = 1; i < ar2.size(); i++){
        if(ar2[i].first - ar2[i - 1].first <= d){
            dp2[i] = dp2[i - 1] + ar2[i].second;
        }else{
            dp2[i] = ar2[i].second;
        }
    }

    int mx2 = 0;
    for(int i = 0; i < ar2.size(); i++) mx2 = max(mx2, dp2[i]);

    cout << mx1 + mx2 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

