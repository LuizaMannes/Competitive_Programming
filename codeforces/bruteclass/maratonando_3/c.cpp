#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int,int> mp;
    int bp=n;
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(!mp[a[i]]){
            mp[a[i]]++;
        }else{
            bp=i;
            break;
        }
 
    }
    cout << n-bp << endl;
    
    
}
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
        
    }
 
 
    return 0;
}
