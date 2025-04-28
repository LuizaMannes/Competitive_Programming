#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;
vector<int> seg(maxn * 4);
vector<int> ar(maxn);

void query(int p, int l, int r, int i, int a = 0){
    if(l == r){
        seg[p] = 1;
        cout << ar[l] << " ";
    }else{
        int mid = (l + r) / 2;
        if(mid - (seg[p * 2] + a) >= i) query(p * 2, l, mid, i, a);
        else query(p * 2 + 1, mid + 1, r, i, a + seg[p * 2]);

        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i< n; i++) cin >> ar[i];

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a--;
        query(1, 0, n - 1, a);
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

