#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n; cin >> n;
    string s,res; cin >> s;
    while(s.size()){
        int val=0;
        if(s.back()=='0'){
            val=stol(s.substr(s.size()-3,2));
            s.pop_back();
            s.pop_back();
            s.pop_back();
        } else {
            val=stol(s.substr(s.size()-1,1));
            s.pop_back();
        }
        char c='a'+val-1;
        res+=c;
    }
    reverse(res.begin(),res.end());
    cout << res << endl;
    
}
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
