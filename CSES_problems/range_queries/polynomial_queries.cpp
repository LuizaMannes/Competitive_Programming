#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using pii = pair<int, int>;

const int maxn = 2e5 + 5;
int seg[4 * maxn];
vector<pii> lazy(4 * maxn);

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p] = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void push(int p, int l, int r){
    if(lazy[p].second){
        auto [a, d] = lazy[p];
        seg[p] += a * (r - l + 1) + d * (r - l) * (r - l + 1) / 2;

        if(l != r){
            int mid = (l + r) / 2;
            lazy[p * 2].first += a;
            lazy[p * 2].second += d;
            lazy[p * 2 + 1].first += a + (mid + 1 - l) * d;
            lazy[p * 2 + 1].second += d;
        }

        lazy[p] = pii(0, 0);
    }
}

void update(int p, int l, int r, int L, int R){
    push(p, l, r);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[p] = pii(1 + (l - L) * 1, 1);
        push(p, l, r);
    }else{
        int mid = (l + r) / 2;
        update(p * 2, l, mid, L, R);
        update(p * 2 + 1, mid + 1, r, L, R);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
    push(p, l, r);
    if(l > R || r < L) return 0;
    if(l >= L && r <= R){
        return seg[p];
    }else{
        int mid = (l + r) / 2;
        int ql = query(p * 2, l, mid, L, R);
        int qr = query(p * 2 + 1, mid + 1, r, L, R);

        return ql + qr;
    }
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int a, b; cin >> a >> b;
            a--; b--;

            update(1, 0, n - 1, a, b);
        }else{
            int a, b; cin >> a >> b;
            a--; b--;

            cout << query(1, 0, n - 1, a, b) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

