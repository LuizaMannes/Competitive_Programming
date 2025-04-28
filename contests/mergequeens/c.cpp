#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m;cin >> n >> m;
    vector<int> gan(n);
    vector<int> gabi(n);
    vector<vector<int>> ami(m,vector<int>(n));
    int cont = 0;
    int count = 0;
    bool ok = true;
    for(int i=0;i<n;i++) cin >> gan[i];
    for(int i=0;i<n;i++){
        cin >> gabi[i];
        if(gabi[i]==gan[i]) cont++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> ami[i][j];
            if(ami[i][j]==gan[j]) count++;
            if(cont==count) ok = false;
        }
        count = 0;
    }
    cout << (ok ? "SIM" : "NAO") << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

