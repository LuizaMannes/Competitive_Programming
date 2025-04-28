#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s;cin >> s;

    vector<int> freq[n];
    vector<int> ar(26);
    for(int i=0;i<n;i++){
        ar[s[i]-'a']++;
        freq[i]=ar;
    }
    
    int a=0;
    bool ok=true;
    for(int i=n;i>1;i--){
        if(n%i) continue;
        a=n/i;
        ok=true;
        for(int j=a+a;j<=n;j+=a){
            for(int k=0;k<26;k++){
                if(freq[j-1][k]-freq[j-a-1][k]!=freq[a-1][k]) ok = false;
            }
        }
        if(ok) break;
    }

    if(!ok){
        cout << '*' << endl;
        return;
    }

    for(int i=0;i<a;i++) cout << s[i];
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

