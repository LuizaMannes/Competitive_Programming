#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Node{
    int m, suf, pref, sum;
}seg[maxn * 4];

void build(int p, int l, int r, vector<int> &ar){
        if(l == r){
            seg[p].suf = seg[p].m = seg[p].pref = seg[p].sum = ar[l];
        }else{
            int mid = (l + r) / 2;
            build(p * 2, l, mid, ar);
            build(p * 2 + 1, mid + 1, r, ar);
        
            seg[p].sum = seg[p * 2].sum + seg[p * 2 + 1].sum;
            seg[p].suf = max(seg[p * 2 + 1].suf, seg[p * 2 + 1].sum + seg[p * 2].suf);
            seg[p].pref = max(seg[p * 2].pref, seg[p * 2].sum + seg[p * 2 + 1].pref);
            seg[p].m = max(seg[p * 2].m, seg[p * 2 + 1].m);
            seg[p].m = max(seg[p].m, seg[p * 2].suf + seg[p * 2 + 1].pref);
        }
}

void update(int p, int l, int r, int i, int k){
        if(l == r){
            seg[p].suf = seg[p].m = seg[p].pref = seg[p].sum = k;
        }else{
            int mid = (l + r) / 2;
            if(i <= mid) update(p * 2, l, mid, i, k);
            else update(p * 2 + 1, mid + 1, r, i, k);
        
            seg[p].sum = seg[p * 2].sum + seg[p * 2 + 1].sum;
            seg[p].suf = max(seg[p * 2 + 1].suf, seg[p * 2 + 1].sum + seg[p * 2].suf);
            seg[p].pref = max(seg[p * 2].pref, seg[p * 2].sum + seg[p * 2 + 1].pref);
            seg[p].m = max(seg[p * 2].m, seg[p * 2 + 1].m);
            seg[p].m = max(seg[p].m, seg[p * 2].suf + seg[p * 2 + 1].pref);
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

