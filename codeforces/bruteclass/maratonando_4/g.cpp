#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s;cin >> s;
    reverse(s.begin(),s.end());
    int cont=0;
    int a=1;
    vector<int> ar;
    for(int i=0;i<s.size();i++){
        if(s[i]!='0'){
            cont++;
            ar.push_back(stol(s.substr(i,1)));
        }else{
            ar.push_back(stol(s.substr(i,1)));
        }
    }
    for(int i=0;i<ar.size();i++){      
        ar[i]=ar[i]*a;
        a=(a<<3)+(a<<1);
    }
    cout << cont << endl;
    for(int i=0;i<ar.size();i++){
        if(ar[i]!=0){
            cout << ar[i] <<' ';
        }
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >>tc;
    while(tc--){
        solve();
    }
}

