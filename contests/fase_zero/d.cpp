#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    long double e,v; cin >> e >> v;
    long double d=e/v;
    long double partedecimal=d-floor(d);
    long double b=floor(partedecimal*100);
    long double p = ceil(b*(0.6));
    int a=d;
    int horas = (19+(a%24))%24;
    int minutos = p;
     
    if(horas <=9) cout << 0;
    cout << horas << ":";
    if(minutos<=9) cout << 0;
    cout << minutos << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

