#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(k);
    for(int i = 0; i < k; i++) cin >> ar[i];
    sort(ar.begin(), ar.end());

    vector<int> w(n + 1);
    w[0] = 0;
    w[1] = 1;
    cout << "W"; 
    for(int i = 2; i <= n; i++){
        bool ok = 0;
        for(int j = 0; j < k; j++){
            if(ar[j] > i) break;
            if(!w[i - ar[j]]) {
                ok = 1;
                break;
            }
        }

        if(ok){
            cout << "W";
            w[i] = 1;
        }else {
            cout << "L";
        }
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

