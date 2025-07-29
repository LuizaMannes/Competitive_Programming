#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

const int mx = 1e6 + 6;
int seg[4 * mx], lpf[mx]; 

vector<int> factorize(int a) {
    vector<int> f;
    int n = a;
    while (n > 1) {
        f.push_back(lpf[n]);
        n /= lpf[n];
    }
    f.erase(unique(f.begin(), f.end()), f.end());

    return f;
}

void update(int p, int l, int r, int i, int x){
    if(l == r) seg[p] += x;
    else {
        int mid = (l + r) / 2;
        if(i <= mid) update(p * 2, l, mid, i, x);
        else update(p * 2 + 1, mid + 1, r, i, x);

        seg[p] = max(seg[p * 2],  seg[p * 2 + 1]);
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 2; i < mx; i++){
        if(lpf[i] == 0){
            lpf[i] = i;
            for(int j = i + i; j < mx; j += i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }

    vector<int> on(mx, -1);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        on[a] = (on[a] == 1? -1: 1);
        vector<int> f = factorize(a);
        for(int j: f) {
            update(1, 0, mx - 1, j, on[a]);
        }
        cout << seg[1] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

