#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n), f(n + 1);
    for(int i = 0; i < n; i++) cin >> ar[i], f[ar[i]]++;

    vector<int> divs[n + 1];
    for(int i = 1; i <= n; i++){
        if(!f[i]) continue;
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                divs[i].push_back(j);
                if(i/j != j) divs[i].push_back(i / j);
            }
        }
    }


    vector<int> ff(n + 1), mx, vis(n + 1);
    int res = 0;
    for(int i = 0; i < n; i++){
        vector<int> next;
        for(int j = 0; j < divs[ar[i]].size(); j++){
            ff[divs[ar[i]][j]]++;
            if(divs[ar[i]][j] == 1) continue;
            if(ff[divs[ar[i]][j]] == i + 1 and !vis[divs[ar[i]][j]]){
                next.push_back(divs[ar[i]][j]);
                continue;
            }
            res = max(res, ff[divs[ar[i]][j]]);
        }
        
        for(int j = 0; j < mx.size(); j++){
            if(ff[mx[j]] != i + 1) res = max(res , ff[mx[j]]), vis[j] = 0;
            else next.push_back(mx[j]);
        }

        swap(next, mx);
        cout << res << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

