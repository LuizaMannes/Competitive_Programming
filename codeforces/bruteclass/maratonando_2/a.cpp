
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int>freq(26,-1);
    string s; cin >> s;
    if(n==2){
        if(s[0]==s[1]) cout << "NO" << endl;
        else cout << "YES" << endl; 
        return;
    } 
    if(n==1) {
        cout << "YES" << endl; 
        return;
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        int pos = s[i]-'a';
        if (freq[pos]==-1){
            if(c==0){
                freq[pos] = 1;
                c = 1;   
            } else {
                c = 0;
                freq[pos] = 0;
            }
        
        } else c = freq[pos];
    }
    bool certo = true;
 
    for(int i=1;i<=n-2;i++){
        if((freq[s[i] - 'a'] == freq[s[i-1] - 'a']) || (freq[s[i] - 'a'] == freq[s[i+1] - 'a'])) certo = false;
    }
    if (certo) cout << "YES" << endl;
    else cout << "NO" << endl;
 
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }  
}
