#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
const int inf = 1e9;
int seg[4 * maxn];

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p] = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);
        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int p, int l, int r, int u, int k){
    if(l == r){
        seg[p] = k;
    }else{
        int mid = (l + r) / 2;
        if(u <= mid) update(p * 2, l, mid, u, k);
        else update(p * 2 + 1, mid + 1, r, u, k);

        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}

int query(int p, int l, int r, int R, int L){
    if(l > R || r < L) return inf;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid, R, L);
    int qr = query(p * 2 + 1, mid + 1, r, R, L);

    return min(ql, qr);
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    map<int,int> li;
    vector<int> v(n);
    for(int i = n - 1; i >= 0; i--){
        if(!li[ar[i]]) v[i] = inf;
        else v[i] = li[ar[i]];
        li[ar[i]] = i;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

