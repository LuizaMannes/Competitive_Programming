#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    int n=s.size();

    int res=0;
    int aux=1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]) aux++;
        else aux=1;
        res=max(res,aux);
    }
    res=max(res,aux);

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

