#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s, t; cin >> s >> t;

    vector<int> p(t.size());
    for(int i = 1, j = 0; i < t.size(); i++){
        while(j > 0 && t[i] != t[j]) j = p[j - 1];  
        if(t[i] == t[j]) j++;
        p[i] = j;
    }

    int res = 0;
    for(int i = 0, j = 0; i < s.size(); i++){
        while(j > 0 && s[i] != t[j]) j = p[j - 1];
        if(s[i] == t[j]) j++;
        if(j == t.size()){
            res++;
            j = p[j - 1];
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

