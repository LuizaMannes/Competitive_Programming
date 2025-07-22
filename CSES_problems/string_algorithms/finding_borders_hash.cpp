#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int p1 = 31;
const int p2 = 37;

void solve() {
    string s; cin >> s;

    int n = s.size();
    vector<int> pot1(n + 1), pot2(n + 1);
    pot1[0] = pot2[0] = 1;
    for(int i = 1; i <= n; i++){
        pot1[i] = (pot1[i - 1] * p1) % mod1;
        pot2[i] = (pot2[i - 1] * p2) % mod2;
    }

    int ph1 = 0, ph2 = 0, sh1 = 0, sh2 = 0;
    for(int i = 0; i < n - 1; i++){
        ph1 = (ph1 + (s[i] - 'a' + 1) * pot1[i]) % mod1;
        ph2 = (ph2 + (s[i] - 'a' + 1) * pot2[i]) % mod2;
        sh1 = (sh1 * p1 + (s[n - i - 1] - 'a' + 1)) % mod1;
        sh2 = (sh2 * p2 + (s[n - i - 1] - 'a' + 1)) % mod2;

        if(ph1 == sh1 && ph2 == sh2) cout << i + 1 << " ";
    }
    
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

