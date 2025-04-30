#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<vector<int>> ar(n, vector<int> (m));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
        }
    }

    vector<int> sl(n), sc(m);

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            sl[i] += ar[i][j];
        }
    }

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            sc[i] += ar[j][i];
        }
    }

    int i = 0, j = 0;

    for(auto c: s){
        if(c == 'R'){
            ar[i][j] = -sc[j];
            sc[j] += ar[i][j];
            sl[i] += ar[i][j];
            j++;
        }

        
        if(c == 'D'){
            ar[i][j] = -sl[i];
            sc[j] += ar[i][j];
            sl[i] += ar[i][j];
            i++;
        }
    }

    ar[i][j] = -sc[j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

