#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s, c; cin >> s >> c;
    int a=s.size()-c.size();
    int res=0;
    for(int i=0;i<=a;i++){
        bool ok=true;
        int b=s.size()-1;
        for(int j=c.size()-1;j>=0;j--){
            if(s[b]==c[j]){
                ok=false;
                break;
            }
            b--;
        }
        if(ok) res++;
        s.pop_back();
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

