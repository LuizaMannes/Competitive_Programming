#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
int seg[4 * mx], lazy[4 * mx];

void push(int p, int l, int r){
    if(lazy[p] != 0){
        seg[p] += lazy[p];
        if(l != r){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
    }

    lazy[p] = 0;
}

void update(int p, int l, int r, int L, int R){
    push(p, l, r);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[p] = 1;
        push(p, l, r);
    }else{
        int mid = (l + r) / 2;
        update(p * 2, l, mid, L, R);
        update(p * 2 + 1, mid + 1, r, L, R);
        seg[p] = max(seg[p * 2] , seg[p * 2 + 1]);
    }
}

int query(int p, int l, int r){
    if(l == r) return seg[p];
    int mid = (l + r) / 2;
    int ql = query(p * 2, l, mid);
    int qr = query(p * 2 + 1, mid + 1, r);

    return max(ql, qr);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> ar;
    vector<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;

        q.push_back({a,b - 1});
        ar.push_back(a);
        ar.push_back(a + b - 1);
    }
    sort(ar.begin(),ar.end());
    ar.erase(unique(ar.begin(),ar.end()),ar.end());
    for(auto i:ar) cout << i << endl;

    for(int i = 0; i < n; i++){
        auto [a, b] = q[i];
        int id = upper_bound(ar.begin(),ar.end(), a) - ar.begin();
        int jd = upper_bound(ar.begin(),ar.end(), a + b) - ar.begin();
        id--; jd--;
        update(1, 0, ar.size() - 1, id, jd);
    }

    cout << seg[1] << endl;

    }

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

