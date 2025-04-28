#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 1e3 + 3;
int seg[maxn * 2][maxn * 2];

void build(int n, vector<vector<int>> &ar){
    for(int i = n; i < n * 2; i++){
        for(int j = n; j < n * 2; j++){
            seg[i][j] = ar[i - n][j - n];
        }
    }

    for(int i = n * 2 - 1; i >= n; i--){
        for(int j = n - 1; j > 0; j--){
            seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
        }
    }

    for(int i = n - 1; i > 0; i--){
        for(int j = n * 2 - 1; j > 0; j--){
            seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
        }
    }
}

void iupdate(int i, int j, int n, int x){
    j += n;
    if(x == -1) seg[i][j] ^= 1;
    else seg[i][j] = x;

    for(j >>= 1; j > 0; j >>= 1){
        seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
    }
}

void update(int i, int j, int n){
    i += n;
    iupdate(i, j, n, -1);

    for(i >>= 1; i > 0; i >>= 1){
        int x = seg[i * 2][j + n] + seg[i * 2 + 1][j + n];
        iupdate(i, j, n, x);
    }
}

int iquery(int i, int b, int d, int n){
    int res = 0;

    for(b += n, d += n + 1; b < d; b >>= 1, d >>= 1){
        if(b & 1) res += seg[i][b++];
        if(d & 1) res += seg[i][--d];
    }

    return res;
}

int query(int a, int b, int c, int d, int n){
    int res = 0;
    
    for(a += n, c += n + 1; a < c; a >>= 1, c >>= 1){
        if(a & 1) res += iquery(a++, b, d, n);
        if(c & 1) res += iquery(--c, b, d, n);
    }

    return res;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<vector<int>> ar(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a; cin >> a;
            ar[i][j] = (a == '*');
        }
    }

    build(n, ar);

    while(q--){
        int k; cin >> k;
        if(k == 1){
            int i, j; cin >> i >> j;
            i--; j--;
            update(i, j, n);
        }else{
            int a, b, c, d; cin >> a >> b >> c >> d;     
            a--; b--; c--; d--;
            cout << query(a, b, c, d, n) << endl;
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

