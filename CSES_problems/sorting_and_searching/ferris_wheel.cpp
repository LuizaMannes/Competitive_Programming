#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,x;cin >> n >> x;

    vector<int> c(n);
    for(auto &i: c) cin >> i;

    sort(c.begin(),c.end());

    int res=n;
    int i=0,j=n-1;
    while(i<j){
        if(c[i]+c[j]<=x){
            res--;
            i++;
            j--;
            continue;
        }
        j--;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

