#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e6 + 6;

struct s{
    vector<int> seg;

    void build(){
        seg.assign(mx * 4, 0);
    }

    void update(int p, int l, int r, int i, int x){
        if(l == r) seg[p] = x;
        else{
            int mid = (l + r) / 2;
            if(i <= mid) update(p * 2, l, mid, i, x);
            else update(p * 2 + 1, mid + 1, r, i, x);

            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        }
    }

    int query(int p, int l, int r, int L, int R){
        if(l > R || r < L) return 0;
        if(l >= L && r <= R) return seg[p];
        else{
            int mid = (l + r) / 2;
            int ql = query(p * 2, l, mid, L, R);
            int qr = query(p * 2 + 1, mid + 1, r, L, R);

            return ql + qr;
        }
    }
};

void solve() {
    int n; cin >> n;

    vector<int> ar(n), b(n);
    s ri, le;
    
    ri.build();
    le.build();

    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        b[i] = ar[i];
    }
    sort(b.begin(), b.end());

    vector<int> mp(n);
    for(int i = 0; i < n; i++){
        int ind = lower_bound(b.begin(), b.end(), ar[i]) - b.begin();
        ri.update(1, 0, n - 1, ind, 1);
        mp[i] = ri.query(1, 0, n - 1, ind + 1, n - 1);
    }

    vector<int> mf(n);
    for(int i = n - 1; i >= 0; i--){
        int ind = lower_bound(b.begin(), b.end(), ar[i]) - b.begin();
        le.update(1, 0, n - 1, ind, 1);
        mf[i] = le.query(1, 0, n - 1, 0, ind - 1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += mf[i] * mp[i];
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
