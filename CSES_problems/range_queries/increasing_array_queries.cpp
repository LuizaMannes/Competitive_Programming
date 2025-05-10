#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 2e5 + 5;

struct Nodo{
    int mx,idx; 
}seg[maxn * 4];

const Nodo nulo = {0, 0};

void build(int p, int l, int r, vector<int> &ar){
    if(l == r){
        seg[p].mx = ar[l];
        seg[p].idx = l;
    }
    else{
        int mid = (l + r) / 2;
        build(p * 2, l, mid, ar);
        build(p * 2 + 1, mid + 1, r, ar);

        seg[p].mx = max(seg[p * 2].mx, seg[p * 2 + 1].mx);
        if(seg[p * 2].mx >= seg[p * 2 + 1].mx) seg[p].idx = seg[p * 2].idx;
        else seg[p].idx = seg[p * 2 + 1].idx;
    }
}

Nodo query(int p, int l, int r, int L, int R){
    if(l > R || r < L) return nulo;
    if(l >= L && r <= R) return seg[p];

    int mid = (l + r) / 2;
    Nodo ql = query(p * 2, l, mid, L, R);
    Nodo qr = query(p * 2 + 1, mid + 1, r, L, R);
    
    return (ql.mx >= qr.mx ? ql : qr);
}

int ind(int L, int R, int n){
    Nodo ans = query(1, 0, n - 1, L, R);
    return ans.idx;
}

void solve() {
    int n, q; cin >> n >> q;
    
    vector<int> ar(n), pref(n + 1), c(n), m;
    for(int i = 0; i < n; i++) cin >> ar[i];

    for(int i = 1; i <= n; i++) pref[i] = ar[i - 1] + pref[i - 1];  

    for(int i = n - 1; i >= 0; i--){
        while(!m.empty() && ar[m.back()] <= ar[i]){
            m.pop_back();
        }
        
        if(m.empty()) c[i] = ar[i] * (n - i);
        else c[i] = c[m.back()] + ar[i] * (m.back() - i);

        m.push_back(i);
    }


    build(1, 0, n - 1, ar);
    while(q--){
        int a, b; cin >> a >> b;
        a--;
        b--;
        
        int maior = ind(a, b, n);
        int s = c[a] - c[maior] + ar[maior] * (b - maior + 1);
        cout << s - (pref[b + 1] - pref[a]) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

