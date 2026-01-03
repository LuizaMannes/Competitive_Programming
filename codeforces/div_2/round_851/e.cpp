#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

int n, m;
vector<ll> t;
const ll neutral = -1e9 + 9;

ll merge(ll a, ll b) { return max(a, b); }
inline int lc(int p) { return p * 2; }
inline int rc(int p) { return p * 2 + 1; }

void build() {
    m = n + 2;
    t.assign(m * 2, neutral);
}

ll query(int l, int r) {
    ll ansl = neutral, ansr = neutral;
    for (l += m, r += m + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ansl = merge(ansl, t[l++]);
        if (r & 1) ansr = merge(t[--r], ansr);
    }
    return merge(ansl, ansr);
}

void update(int i, ll x) {
    i += m;
    t[i] = merge(t[i], x);
    for (i >>= 1; i > 0; i >>= 1) t[i] = merge(t[lc(i)], t[rc(i)]);
}

void solve() {
    cin >> n;
    build();

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + ar[i];

    vector<ll> comp = pref;
    sort(comp.begin(), comp.end());

    vector<ll> dp(n + 1);
    int id = lower_bound(comp.begin(), comp.end(), pref[0]) - comp.begin();
    update(id, 0);
    for(int i = 1; i <= n; i++){
        id = lower_bound(comp.begin(), comp.end(), pref[i]) - comp.begin();
        dp[i] = max(dp[i - 1], i + query(0, id));
        update(id, dp[i] - i);
    }

    cout << dp[n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

