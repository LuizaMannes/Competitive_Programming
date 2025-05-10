#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Node{
    int m, suf, pref, sum;
}seg[maxn * 4];

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

void update(int p, int l, int r, int i, int k){
        if(l == r){
            seg[p].suf = seg[p].m = seg[p].pref = seg[p].sum = k;
        }else{
            int mid = (l + r) / 2;
            if(i <= mid) update(p * 2, l, mid, i, k);
            else update(p * 2 + 1, mid + 1, r, i, k);
        
            seg[p] = sum(seg[p * 2], seg[p * 2 + 1]);
        }

}

void solve() {
    int n, q; cin >> n >> q;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    
    build(1, 0, n - 1, ar);

    while(q--){
        int i, k; cin >> i >> k;
        i--;
        update(1, 0, n - 1, i, k);
        cout << max(0ll, seg[1].m) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

