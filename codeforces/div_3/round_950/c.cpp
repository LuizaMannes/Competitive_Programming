#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> ar1(n);
    vector<int> ar2(n);
    map<int,int> freq;
    map<int,int> safe;
    int pre=0;
    for(int i=0;i<n;i++) cin >> ar1[i];
    for(int i=0;i<n;i++) cin >> ar2[i];
    for(int i=0;i<n;i++){
        safe[ar2[i]]++;
        if(ar1[i]!=ar2[i]){
            freq[ar2[i]]++;
            pre++;
        }
    }
    bool ok=true;
    int m; cin >> m;
    vector<int> ar3(m);
    bool ei=false;
    for(int i=0;i<m;i++) cin >> ar3[i];
    for(int i=0;i<m;i++){
        if(!safe[ar3[i]]){
            ei=true;
        }
        if(ei){
            if(safe[ar3[i]]) ei=false;
        }
        if(freq[ar3[i]]){
            freq[ar3[i]]--;
            pre--;
        }
    }
    if(pre!=0 || ei) ok=false;
    cout << (ok?"YES":"NO") << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

