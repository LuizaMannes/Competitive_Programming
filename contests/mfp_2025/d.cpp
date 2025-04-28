#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const double pi = 3.14159265359;

void solve() {
    int r1, r2, r3; cin >> r1 >> r2 >> r3;
    vector<int>r(4);
    r[1] = r1;
    r[2] = r2;
    r[3] = r3;
    int l, q; cin >> l >> q;
    
    double c1 = (double) r1 * 2 * pi, c2 = (double) r2 * 2 * pi, c3 = (double) r3 * 2 * pi;
    double d1 = c1 / (double) l, d2 = c2 / (double) l, d3 = c3 / (double) l;
    vector<double> ds(4);
    ds[1] = d1;
    ds[2] = d2;
    ds[3] = d3;

    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(d > b) swap(d, b);
        double aux = min(b - d, d + (l - b));
        double res1 = ds[1] * aux + abs(r[a] - r[1]) + abs(r[c] - r[1]);
        double res2 = ds[2] * aux + abs(r[a] - r[2]) + abs(r[c] - r[2]); 
        double res3 = ds[3] * aux + abs(r[a] - r[3]) + abs(r[c] - r[3]);
        cout << fixed << setprecision(10);
        cout << min(min(res1, res2), res3) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

