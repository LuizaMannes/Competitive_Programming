#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Node{
    int m, suf, pref, sum;
}seg[maxn * 4];

const Node neutro = {0, 0, 0, 0};

Node sum(Node a, Node b){
    Node c;
    c.sum = a.sum + b.sum;
    c.suf = max(b.suf, b.sum + a.suf);
    c.pref = max(a.pref, a.sum + b.pref);
    c.m = max(a.m, b.m);
    c.m = max(c.m, a.suf + b.pref);

    return c;
}

void build(int p, int l, int r, vector<int> &ar){
        if(l == r){
            seg[p].suf = seg[p].m = seg[p].pref = seg[p].sum = ar[l];
        }else{
            int mid = (l + r) / 2;
            build(p * 2, l, mid, ar);
            build(p * 2 + 1, mid + 1, r, ar);
        
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

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    
    build(1, 0, n - 1, ar);

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << max(0ll, query(1, 0, n - 1, a, b).m) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

