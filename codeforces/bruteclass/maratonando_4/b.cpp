#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> mdc(1e3+6,vector<int>(1e3+6,0));

void clac(){
    for(int i=1;i<1e3+6;i++){
        for(int j=1;j<1e3+6;j++){
            mdc[i][j]=gcd(i,j);
        }
    }
}

void solve() {
    int n; cin >> n;
    const int maxn = 1006; 
    vector<int> arr(n);
    vector<int> ARR(maxn, -1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ARR[arr[i]] = i;
    }
    int res = -1;
    for(int i=0;i<n;i++){
        for(int j=1;j<maxn;j++){
            if(ARR[j] > -1 && mdc[arr[i]][j]==1){
                res=max(i + ARR[j] + 2,res);
            }
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    clac();
    while(tc--){
        solve();
    }
    return 0;
}

