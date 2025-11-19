#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int MAX = 1e7 + 5;

int seg[MAX], lazy[MAX], R[MAX], L[MAX], ptr = 2;

int lc(int i){
    if(L[i] == 0) L[i] = ptr++;
    return L[i];
}

int rc(int i){
    if(R[i] == 0) R[i] = ptr++;
    return R[i];
}

void push(int p, int l, int r){
    if(!lazy[p]) return;
    seg[p] = r - l + 1 - seg[p];
    if(l != r){
        lazy[lc(p)] ^= lazy[p];
        lazy[rc(p)] ^= lazy[p];
    }
    lazy[p] = 0;
}

int query(int p, int l, int r, int L, int R){
    push(p, l, r);
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[p];
    int mid = l + (r - l) / 2;

    int ql = query(lc(p), l, mid, L, R);
    int qr = query(rc(p), mid + 1, r, L, R);

    return ql + qr;
}

void update(int p, int l, int r, int L, int R){
    push(p, l, r);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[p] ^= 1;
        push(p, l, r);
    }else{
        int mid = l + (r - l) / 2;
        update(lc(p), l, mid, L, R);
        update(rc(p), mid + 1, r, L, R);
        seg[p] = seg[lc(p)] + seg[rc(p)];
    }

}

void solve() {
    int n; cin >> n;

    vector<tuple<int,int,int>> ar(2 * n);
    for(int i = 0; i < 2 * n; i+=2){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(b > d) swap(b,d);
        ar[i] = {a, b, d};
        ar[i + 1] = {c, b, d};
    }

    sort(ar.begin(), ar.end());

    int res = 0, last = 0;
    for(int i = 0; i < 2*n; i++){
        auto [a, b, d] = ar[i];
        res += (a - last) * query(1, 0, 1e9, 0, 1e9);

        update(1, 0, 1e9, b, d - 1);
        last = a;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

