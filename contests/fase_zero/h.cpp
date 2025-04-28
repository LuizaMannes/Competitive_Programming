#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

bool prime(int a){
    if(a==1) return false;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return false;
    }
    return true;
}

void solve() {
    int x; cin >> x;
    if(x==3){
        cout << -1 << endl;
        return;
    }
    int a=x/2+1;
    int b=x/2;
    while(prime(a) || prime(b)){
        b--;
        a++;
    }
    cout << b << " " << a << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

