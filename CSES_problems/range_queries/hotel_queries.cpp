#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
int seg[maxn * 4];

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p] = ar[l];
    }else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);
        
        seg[p] = max(seg[p *2], seg[p * 2 + 1]);
    }
}

void query(int p, int l, int r, int x){
    if(l == r){
        seg[p] -= x;
        cout << l + 1 << " ";
    }else{
        int mid = (l + r) / 2;
        if(seg[p * 2] >= x) query(p * 2, l, mid, x);
        else query(p * 2 + 1, mid + 1, r, x);

        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    build(1, 0, n - 1, ar);

    for(int i = 0; i < m; i++){
       int x; cin >> x;
       if(seg[1] < x) cout << 0 << " ";
       else query(1, 0, n - 1, x);
    }

    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

