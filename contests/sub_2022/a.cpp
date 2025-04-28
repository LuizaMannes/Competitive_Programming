#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    int cont = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'a') cont++;
        else{
            if(cont > 1) ans += cont;
            cont = 0;
        }
    }
    if(cont > 1) ans+=cont;

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

