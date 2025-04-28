#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    if(n==0){
        cout << '*' << endl;
        cout << '*' << endl;
        return;
    }

    for(int i=0;i<n;i++){
        cout << 'I';
        if(i==4 && n!=5) cout << endl;
    }
    cout << endl;
    if(n<=5) cout << '*' << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

