#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 4e5 + 5;
int seg[maxn * 4];

void update(int p, int l, int r, int i, int k){
    if(l == r){
        seg[p] += k;
    }else{
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, k);
        else update(p * 2 + 1, mid + 1, r, i, k);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int p, int l, int r, int L, int R){
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
    vector<int> c = ar;
    vector<tuple<int,int,int>> qr;

    while(q--){
        char ch; cin >> ch;
        int a, b; cin >> a >> b;
        qr.push_back({ch == '?', a, b});
        if(ch == '!') c.push_back(b);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    
    int s = c.size() - 1;
    for(int i = 0; i < n; i++){
        int id = upper_bound(c.begin(), c.end(), ar[i]) - c.begin();
        id--;
        update(1, 0, s, id, 1);
    }

    for(auto [t, a, b]: qr){
        if(t){
            int idx = upper_bound(c.begin(), c.end(), a - 1) - c.begin();
            idx--;
            int id = upper_bound(c.begin(), c.end(), b) - c.begin();
            id--;
            cout << query(1, 0, s, 0, id) - query(1, 0, s, 0, idx) << endl;
            
        }else{
            a--;
            int id = upper_bound(c.begin(), c.end(), ar[a]) - c.begin();
            id--;
            update(1, 0, s, id, -1);
            id = upper_bound(c.begin(), c.end(), b) - c.begin();
            id--;
            update(1, 0, s, id, 1);
            ar[a] = b;
        }   
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

