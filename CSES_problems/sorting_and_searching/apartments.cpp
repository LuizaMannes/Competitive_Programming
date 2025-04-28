#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m,k;cin >> n >> m >> k;
    
    vector<int> ar(n);
    vector<int> ap(m);

    for(auto &i: ar) cin >> i;
    for(auto &i: ap) cin >> i;

    sort(ar.begin(),ar.end());
    sort(ap.begin(),ap.end());

    int i=0, j=0, res=0;
    while(i<n && j<m){
        if(ar[i]-k>ap[j]){
            j++;
            continue;
        }
        if(ar[i]+k<ap[j]){
            i++;
            continue;
        }
        res++;
        i++;
        j++;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

