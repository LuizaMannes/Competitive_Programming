#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    map<int,int> freq;
    for(int i=0;i<n;i++){
        cin >> ar[i];
        freq[ar[i]]++;
        if(!freq[ar[i]+1]) freq[ar[i]+1]=0;
    }
    int res=0;
    int ult=0;
    for(auto[m,p]:freq){
        res+=max(0,ult-p);
        ult=p;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

