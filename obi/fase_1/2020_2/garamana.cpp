#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s, c; cin >> s >> c;
    vector<int> freq(26);
    for(int i=0;i<s.size();i++){
        int pos=s[i]-'a';
        freq[pos]++; 
    }
    bool ok=true;
    for(int i=0;i<c.size();i++){
        int pos=c[i]-'a';
        if(c[i]=='*') continue;
        if(freq[pos]==0) ok=false;
        freq[pos]--;
    }
    if(ok) cout << "S" << endl;
    else cout << "N" << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

