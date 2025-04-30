#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int res=0;
    char evil='1';
    
    if(n==1) {
        cout << res << endl;
        return;
    }
    bool loob=true;
    for(int i=0;i<n;i++){
       if(s[i]=='1' && loob==true){
            evil^=1;
            loob=false;
       }
       if(s[i]==evil){
            evil^=1;
            res++;
       }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        solve();
    }
}

   
     
