#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    vector<int> dif;
    for(int i=1;i<n;i++){
        if(ar[i]<ar[i-1]){
            dif.push_back(ar[i-1]-ar[i]);
            ar[i]=ar[i-1];
        }
    }
    sort(dif.begin(),dif.end());
    int last=0;
    int m=dif.size()+1;
    int res=0;
    for(auto c:dif){
        res+=(c-last)*m;
        m--;
        last=c;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

