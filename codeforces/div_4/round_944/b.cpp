#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s; cin >> s;
    int cont=0;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            cont++;
        }else {
            swap(s[i],s[i-1]);
        }
    }
    if(cont == s.size()-1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << s << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

