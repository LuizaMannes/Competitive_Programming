#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    int l; cin >> l;
    vector<int> luz(m, 0);
    while(l--){
        int x; cin >> x;
        luz[x-1] = 1;
    }
    
    vector<vector<int>> aux(n);

    for(int i = 0; i < n; i++){
        int l; cin >> l;
        for(int j = 0; j < l; j++){
            int x; cin >> x;
            aux[i].push_back(x-1);
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        bool ok = true;
        /*cout << "1 =";
        for(auto u : luz) cout << u << ' ';
        cout << endl;*/


        for(int j = 0; j < m; j++){
            if(luz[j] == 0) continue;
            ok = false;
            break;
        }
        
        if(ok){
            //cout << "entra aq\n";
            break;
        }
        ans++;

        for(int j = 0; j < (int)aux[i].size(); j++){
            if(luz[aux[i][j]] == 1) luz[aux[i][j]] = 0;
            else luz[aux[i][j]] = 1;
        }
      
    }
    /*for(auto u : luz) cout << u << ' ';
    cout << endl;*/


    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < m; j++){
            if(luz[j] == 0) continue;
            ok = false;
            break;

        }
        
        if(ok) break;
        ans++;

        for(int j = 0; j < (int)aux[i].size(); j++){
            if(luz[aux[i][j]] == 1) luz[aux[i][j]] = 0;
            else luz[aux[i][j]] = 1;
        }
        //cout << "2 = ";
        /*for(auto u : luz) cout << u << ' ';
        cout << endl;*/
    }
    
    bool res = true;
    for(auto u : luz){
        if(u == 1) res = false;
    }

    if(res) cout << ans << endl;
    else cout << -1 << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

