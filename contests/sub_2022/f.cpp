#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,c;cin >> n >> c;
    map<string,int> freq;
    
    for(int i=0;i<n;i++){
        string s;cin >> s;
        int aux=0;
        for(int j=0;j<c;j++){
            if(s[j]=='*') aux=j;
        }
        
        char a='a';
        for(int j=0;j<26;j++){
            s[aux]=a;
            a++;
            freq[s]++;
        }
    }
    
    int ans=0;
    string res;
    for(auto [a,b] : freq){
        if(b>ans){
            ans=b;
            res=a;
        }
    }

    cout << res << ' ' << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

