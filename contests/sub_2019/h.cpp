#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int v, p; cin >> v >> p;
    int aux=v*p;
    for(int i=1;i<=9;i++){
        int x = (aux*i*10);
        if(x % 100 != 0){
            x /= 100;
            x++;
        }
        else{
            x /= 100;
        }
        cout << x << " ";
    }
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

