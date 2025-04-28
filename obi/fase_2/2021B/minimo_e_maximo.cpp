#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int s,a,b;cin >> s >> a >> b;

    for(int i=a;i<=b;i++){
        string t=to_string(i);
        
        int c=0;
        for(int i=0;i<(int)t.size();i++){
            c+=t[i]-'0';
        }

        if(c==s){
            cout << i << endl;
            break;
        }
    }

    for(int i=b;i>=a;i--){
        string t=to_string(i);
        
        int c=0;
        for(int i=0;i<(int)t.size();i++){
            c+=t[i]-'0';
        }

        if(c==s){
            cout << i << endl;
            break;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

