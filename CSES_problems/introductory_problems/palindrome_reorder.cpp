#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    sort(s.begin(), s.end());

    map<char,int> m;
    for(int i = 0; i < s.size(); i++) m[s[i]]++;

    string r;
    int ok = 0;
    char mid;
    for(auto [c, f]: m){
        if(f & 1){
            ok++;
            mid = c;
        }
        if(ok == 2){
            cout << "NO SOLUTION" << endl;
            return;
        }
        for(int i = 1; i * 2 <= f; i++){
            r.push_back(c);
        }
    }

    string t = r;
    reverse(t.begin(), t.end());

    if(mid) r.push_back(mid);
    r += t;
    
    cout << r << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

