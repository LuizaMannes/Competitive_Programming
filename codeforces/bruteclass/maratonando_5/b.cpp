#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

void solve() {
    string s, s2; cin >> s;
    int ok = 0, OK = 0;
    for(int i = (int)s.size()-1; i >= 0; i--){
        if(s[i] == 'b'){
            ok++;
        }
        else if(s[i]  == 'B'){
            OK++;
        }
        else if(ok || OK){
            if(s[i] > 90){
                if(ok){
                    ok--;
                }
                else{
                    s2 += s[i];
                }
            }
            else{
                if(OK){
                    OK--;
                }
                else{
                    s2 += s[i];
                }
            }
        }
        else{
            s2 += s[i];

        }
    }
    for(int i = (int)s2.size()-1; i >= 0; i--){
        cout << s2[i];
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

