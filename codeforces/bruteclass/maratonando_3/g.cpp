#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    string s; cin >>s;
    int n=s.size();
    int l=n/2-1;
    int r=n-1;
    if(s.size()==1 || s.size() & 1){
        cout << "NO" << endl;
        return;
    }
    while(l>-1){
        
        if(s[l]!=s[r]){
            cout << "NO" << endl;
            return;
        }
        l--;
        r--;
 
    }
    cout << "YES" << endl;
 
    
 
}
 
int main(){
    int tc; cin>>tc;
    while(tc--){
        solve();
 
    }
 
 
}
