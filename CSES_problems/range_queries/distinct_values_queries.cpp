#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
using pii = pair<int,int>;

const int maxn = 2e5 + 5;
int seg[maxn * 4];

void update(int p, int l, int r, int i, int k){
    if(l == r) seg[p] = k;
    else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, k);
        else update(p * 2 + 1, mid + 1, r, i, k);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid, L, R);
    int qr = query(p * 2 + 1, mid + 1, r, L, R);

    return ql + qr;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    vector<pii> qr[maxn];
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        qr[a].push_back({b, i});
    }

    map<int,int> li;
    vector<int> res(q);
    for(int i = n - 1; i >= 0; i--){
        if(li[ar[i]]) update(1, 0, n - 1, li[ar[i]], 0);

        li[ar[i]] = i;
        update(1, 0, n - 1, i, 1);

        for(auto [a, b] : qr[i]){
            res[b] = query(1, 0, n - 1, i, a);
        }
    }

    for(int i = 0; i < q; i++) cout << res[i] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

