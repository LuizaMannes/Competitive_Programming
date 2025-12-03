#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    if(ar[0] == n or ar[n - 1] == 1){
        cout << "No" << endl;
        return;
    }
    
    int posm = 0, menor1 = 1e9;
    for(int i = 0; i < n; i++){
        menor1 = min(menor1, ar[i]);
        if(ar[i] == n){
            posm = i;
            break;
        }
    }

    int menor2 = 1e9, maior = 0;
    bool ok = 1;
    for(int i = posm + 1; i < n; i++){
        if(ar[i] < menor1){
            ok = 0;
        }

        if(ar[i] > menor1) ok = 1;
    }

    cout << (ok? "Yes" : "No")  << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

