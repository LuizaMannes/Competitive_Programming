#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
int seg[4 * maxn], lazy[4 * maxn], rep[4 * maxn];

void build(int p, int l, int r, vector<int> &ar){
    if(l == r) seg[p] = ar[l];
    else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void push(int p, int l, int r){
    if(rep[p]){
        seg[p] = lazy[p] * (r - l + 1);
        if(l != r){
            lazy[p * 2] = lazy[p];
            lazy[p * 2 + 1] = lazy[p];
            rep[p * 2] = 1;
            rep[p * 2 + 1] = 1;
        }
    }else{
        seg[p] += lazy[p] * (r - l + 1);
        if(l != r){
            lazy[p * 2] = lazy[p];
            lazy[p * 2 + 1] = lazy[p];
        }
    }
    rep[p] = 0;
    lazy[p] = 0;
}

void update(int p, int l, int r, int L, int R, int x, int repl){
    push(p, l, r);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[p] = x;
        rep[p] = repl;
        push(p, l, r);
    }else{
        int mid = (l + r) / 2;
        update(p * 2, l, mid, L, R, x, repl);
        update(p * 2 + 1, mid + 1, r, L, R, x, repl);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
    push(p, l, r);
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
    
    build(1, 0, n - 1, ar);

    while(q--){
        int t; cin >> t;

        if(t == 1){
            int a, b, x; cin >> a >> b >> x;
            a--; b--;

            update(1, 0, n - 1, a, b, x, 0);
        }else if(t == 2){
            int a, b, x; cin >> a >> b >> x;
            a--; b--;

            update(1, 0, n - 1, a, b, x, 1);
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

