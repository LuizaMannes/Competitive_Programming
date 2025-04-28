#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a;cin >> a;
    vector<vector<int>> ar(a,vector<int> (a));
    
    for(int i=0;i<a;i++){
        for(int j=i;j<a-i;j++){
            for(int k=i;k<a-i;k++){
                ar[j][k]=i+1;
            }
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout << ar[i][j] << " "; 
        }
        cout << endl;
    }
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

