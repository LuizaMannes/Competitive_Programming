#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<vector<int>> ar(n);
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int a; cin >> a;
            ar[i].push_back(a);
        }
    }

    if(n == 2){
        int c1 = 0, c2 = 0;
        bool ok = 1;
        for(int i = 0; i < ar[0].size(); i++){
            if(ar[0][i] == 2) c2++;
            if(ar[0][i] == 1 && c2) ok = 0;
        }

        for(int i = 0; i < ar[1].size(); i++){
            if(ar[1][i] == 1) c1++;
            if(ar[1][i] == 2 && c1) ok = 0;
        }
        if(ar[0].size() && ar[1].size() && ar[0].back() == 2 && ar[1].back() == 1) ok = 0;

        if(!ok) cout << "N" << endl;
        else cout << "S" << endl;
    }else{
        cout << "S" << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

