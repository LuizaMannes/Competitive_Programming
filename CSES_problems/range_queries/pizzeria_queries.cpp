#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
const int inf = 1e9 + 9;
vector<int> pos(4 * maxn), neg(4 * maxn);

void build(int p, int l, int r, int a,vector<int> &ar, vector<int> &seg){
    if(l == r){
        seg[p] = ar[l] + (l * a);
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, a, ar,seg);
        build(p * 2 + 1, mid + 1, r, a, ar, seg);

        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int p, int l, int r, int i, int k, int a, vector<int> &seg){
    if(l == r) seg[p] = k + (l * a);
    else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, k, a, seg);
        else update(p * 2 + 1, mid + 1, r, i, k, a, seg);

        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}

int query(int p, int l, int r, int L, int R, vector<int> &seg){
    if(l > R || r < L) return inf;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid, L, R, seg);
    int qr = query(p * 2 + 1, mid + 1, r, L, R, seg);

    return min(ql, qr);
}

void solve() {
    int n, q; cin >> n >> q;
    
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    build(1, 0, n - 1, 1, ar, pos);
    build(1, 0, n - 1, -1, ar, neg);

    while(q--){
        int a; cin >> a;
        if(a == 1){
            int i, k; cin >> i >> k;
            i--;
            update(1, 0 , n - 1, i, k, 1, pos);
            update(1, 0 , n - 1, i, k, -1, neg);
        }else{
            int i; cin >> i;
            i--;
            cout << min(query(1, 0, n - 1, 0, i, neg) + i, query(1, 0, n - 1, i, n - 1, pos) - i) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

