#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
const int mod = 998244353;

vector<int> par(mx), sz(mx), fat(mx);


int exp_mod(int base, int exp) {
    int b = base, res = 1;
    while (exp) {
        if (exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return res;
}

int inv(int a) { return exp_mod(a, mod - 2); }

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void solve() {
    int n, s; cin >> n >> s;

    for(int i = 0; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
    }

    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < n - 1; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }

    sort(edges.begin(), edges.end());

    vector<int> res(n + 1);
    for(int i = 0; i < n - 1; i++){
        auto [c, u, v] = edges[i];
        
        int a = find(u), b = find(v);
        if(sz[a] < sz[b]) swap(a,b);

        int w = s - c;
        int nres = (res[a] + res[b] + res[a] * res[b]) % mod;

        int comb = w * fat[sz[a] - 1] * inv(fat[sz[b]] * fat[max(sz[a] - 1 - sz[b], 0ll)] % mod) % mod;
        comb = (comb * w * fat[sz[b] - 1] * inv(fat[1] * fat[max(sz[b] - 1 - 1, 0ll)] % mod)) % mod;

        nres = (nres + (nres * comb)) % mod;
        nres = (nres + comb) % mod;

        if(sz[a] == sz[b] && sz[a] == 1) nres = 0;
        unite(u, v);

        a = find(u);
        res[a] = nres;
    }

    cout << res[find(1)] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    fat[0] = 1;
    for(int i = 1; i < mx; i++){
        fat[i] = (fat[i - 1] * i) % mod;
    }

    int tc;cin >> tc; while(tc--) solve();
}

