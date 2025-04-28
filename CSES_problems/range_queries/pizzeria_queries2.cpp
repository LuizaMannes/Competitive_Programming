#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
const int inf = 1e9 + 9;

struct s{
    int seg[4 * maxn];
    void build(int p, int l, int r, int a, vector<int> &ar){
        if(l == r){
            seg[p] = ar[l] + (l * a);
        }else{
            int mid = (l + r) / 2;
            build(p * 2, l, mid, a, ar);
            build(p * 2 + 1, mid + 1, r, a, ar);

            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        }
    }

    void update(int p, int l, int r, int i, int k, int a){
        if(l == r) seg[p] = k + (l * a);
        else{
            int mid = (l + r) / 2;
            if(i <= mid) update(p * 2, l, mid, i, k, a);
            else update(p * 2 + 1, mid + 1, r, i, k, a);

            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        }
    }

    int query(int p, int l, int r, int L, int R){
        if(l > R || r < L) return inf;
        if(l >= L && r <= R) return seg[p];

        int mid = (l + r) / 2;
        int ql = query(p * 2, l, mid, L, R);
        int qr = query(p * 2 + 1, mid + 1, r, L, R);

        return min(ql, qr);
    }
} pos, neg;

void solve() {
    int n, q; cin >> n >> q;
    
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    pos.build(1, 0, n - 1, 1, ar);
    neg.build(1, 0, n - 1, -1, ar);

    while(q--){
        int a; cin >> a;
        if(a == 1){
            int i, k; cin >> i >> k;
            i--;
            pos.update(1, 0 , n - 1, i, k, 1);
            neg.update(1, 0 , n - 1, i, k, -1);
        }else{
            int i; cin >> i;
            i--;
            cout << min(neg.query(1, 0, n - 1, 0, i) + i, pos.query(1, 0, n - 1, i, n - 1) - i) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

