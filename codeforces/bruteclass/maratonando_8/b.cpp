#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int par = 0, impar = 0, menor = 1e9;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] % 2 == 0){
            par++;
        }
        else{
            impar++;
            menor = min(v[i], menor);
        }
    }
    bool ok = true;
    if(par == 0 || impar == 0){
        cout << "YES" << endl;
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(v[i] % 2 == 0 && v[i] <  menor){
                ok = false;
            }
        }
    }
    if(ok){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

signed main() {

    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}
