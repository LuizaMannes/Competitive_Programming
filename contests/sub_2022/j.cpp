#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int N; cin >> N;
    map<int, int> f;
    int a, b; cin >> a >> b;
    int x=10;
    a=min(a,x);
    b=min(b,x);
    if(a > 10) f[10]++; else f[a]++;
    if(b > 10) f[10]++; else f[b]++;
    int j = 24 - (a + b);

    int c, d; cin >> c >> d;
    c=min(x,c);
    d=min(x,d);
    if(c > 10) f[10]++; else f[c]++;
    if(d > 10) f[10]++; else f[d]++;
    int m = 23 - (c + d);

    while(N--){
        int p; cin >> p;
        p=min(x,p);
        if(p > 10) f[10]++; else f[p]++;
        j -= p; m -= p;
    }

    //cout << j << ' ' << m << endl;

    int valj = 10000;
    for(int i = j; i <= 10; i++){
        if(f[i] >= 4) continue;
        valj = i; break;
    }
    if(valj > m) valj = 10000;

    //cout << valj << endl;
    int valm = 10000;
    if(f[m] < 4) valm = m;

    int ans = min(valj, valm);
    if(ans > 10) cout << -1 << endl;
    else cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

