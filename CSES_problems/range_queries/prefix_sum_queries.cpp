#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Node{
    int s, pref;
} seg[4 * maxn];

const Node neutro = {0, 0};

Node sum(Node a, Node b){
    Node c;
    c.s = a.s + b.s;
    c.pref = max(a.pref, a.s + b.pref);

    return c;
}

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p].s = seg[p].pref = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);

        seg[p] = sum(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int p, int l, int r, int i, int k){
    if(l == r){
        seg[p].s = seg[p].pref = k;
    }else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, k);
        else update(p * 2 + 1, mid + 1, r, i, k);

        seg[p] = sum(seg[p * 2], seg[p * 2 + 1]);
    }
}

Node query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return neutro;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    Node ql = query(p * 2, l, mid, L, R);
    Node qr = query(p * 2 + 1, mid + 1, r, L, R);
    
    return sum(ql, qr);
}

int res(int L, int R, int s){
    return query(1, 0, s, L, R).pref;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);

    while(q--){
        int a; cin >> a;
        if(a == 1){
            int i, k; cin >> i >> k;
            i--;
            update(1, 0, n - 1, i, k);
        }else{
            int l, r; cin >> l >> r;
            l--; r--;
            cout << max(0ll, res(l, r, n - 1)) << endl;
        } 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

