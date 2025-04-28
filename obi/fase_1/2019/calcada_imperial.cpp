#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar(n);
    set<int> set;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        set.emplace(ar[i]);     
   }
    int res=0;
    for(auto u:set){
        for(auto v:set){
            int aux=0;
            int ult=0;
            for(int k=0;k<n;k++){
                if(ar[k]==ult || (ar[k]!=u && ar[k]!=v)) continue;
                aux++;
                ult=ar[k];
            }
            res=max(res,aux);
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

