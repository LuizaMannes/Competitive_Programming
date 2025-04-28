#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string n;cin >> n;
    int m;cin >> m;
    int s=n.size();
    
    map<char,char> mapa;
    
    mapa['a'] = mapa['b'] = mapa['c'] = '2';
    mapa['d'] = mapa['e'] = mapa['f'] = '3';
    mapa['g'] = mapa['h'] = mapa['i'] = '4';
    mapa['j'] = mapa['k'] = mapa['l'] = '5';
    mapa['m'] = mapa['n'] = mapa['o'] = '6';
    mapa['p'] = mapa['q'] = mapa['r'] = mapa['s'] = '7';
    mapa['t'] = mapa['u'] = mapa['v'] = '8';
    mapa['w'] = mapa['x'] = mapa['y'] = mapa['z'] = '9';

    int res=0;
    for(int i=0;i<m;i++){
        string a;cin >> a;
        
        if(a.size()!=s) continue;
        
        bool ok=true;
        for(int j=0;j<s;j++){
            if(mapa[a[j]] != n[j]){
                ok = false;
                break;
            }
        }
        if(ok) res++;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

