#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int smx = 2e5 + 5;

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n), pref(n + 1);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        pref[i + 1] = pref[i] + ar[i];
    }
    
    vector<int>  c(pref[n] + 1);
    vector<pair<int,int>> lr(n);
    int q = 0;
    int k = 0;
    int start = 1;
    for(int l = 1; l <= pref[n]; l++){
        c[l] = q;
        k++;
        if(k == ar[q]){
            k = 0;
            lr[q] = {start, l};
            start = l + 1;
            q++;
        }
    }   

    for(int i = 1; i <= m; i++){
        int p = m;
        bool ok = true;
        int last = -1;
        int maxg = m - i + 1;
        for(int j = maxg; j <= pref[n]; j += maxg){
            p -= maxg;
            if(j < lr[c[j]].second){
                if(p - ((pref[c[j] + 1] - pref[last + 1]) - maxg) < 0) ok = false;
                else{
                    p = m;
                    j = lr[c[j]].second;
                }
            }else if(j == lr[c[j]].second) p = m;
            last = c[j];
            if(!ok) break;
            if(p < 0){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << i << endl;
            return;
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

