#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using ii = pair<int,int>;

const int mx = 2e5+5;

vector<int> seg(mx * 4);
vector<ii> lazy(mx * 4);

void push(int u, int l, int r){
    auto [a, p] = lazy[u];

    if(l == r){
        seg[u] += a;
        lazy[u] =  {0,0};
        return;
    }

    int mid = (l+r) / 2;
    
    lazy[u * 2].first += a;
    lazy[u * 2].second += p;
    lazy[u * 2 + 1].first += a + (mid + 1 - l) * p;
    lazy[u * 2 + 1].second += p;

    lazy[u] = {0,0};
}

int query(int u, int l, int r, int i){
    push(u, l, r);

    if(l == r){
        return seg[u];
    }

    int mid = (l + r) / 2;

    if(mid >= i) return query(u * 2, l, mid, i);
    else return query(u * 2 + 1, mid+1, r, i);
}

void update(int u, int l, int r, int L, int R, int v, int p){
    push(u, l, r);

    if(l > R || r < L) return;

    if(l >= L && r <= R){
        lazy[u].first += v + (l - L) * p;
        lazy[u].second += p;
        
        push(u, l, r);

        return;
    }

    int mid = (l+r) / 2;

    update(u * 2, l, mid, L, R, v, p);
    update(u * 2 + 1, mid+1, r, L, R, v, p);
}

void solve() {
    int n, m; cin >> n >> m;
    
    while(m--){
        int a; cin >> a;

        if(a == 1){
            int i, v;cin >> i >> v;

            update(1, 0, n - 1, i - 1, min(n - 1, i + v - 2), v, -1);
        }

        if(a == 2){
            int i, v;cin >> i >> v;

            update(1, 0, n - 1, max(0LL, i - v), i - 1, 1 + max(0LL, v - i), 1);
        }

        if(a == 3){
            int i; cin >> i;
            int res = query(1, 0, n - 1, i - 1);
            cout << res << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

