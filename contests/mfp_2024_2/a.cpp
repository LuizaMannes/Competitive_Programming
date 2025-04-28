#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5;

void solve() {
    int n; cin >> n;
    char aux = 'a';
    string res = "a";
    for(int i = 1;i < n; i++){
        aux++;
        string b = aux + res;
        res += b;
        if(res.size() == 1e5 + 5) break;
    }

    int m = res.size();
    for(int i = 0; i < min(m, mx); i++) cout << res[i];
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

