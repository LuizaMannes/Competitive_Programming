#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> soma(k+5);
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;

        soma[a] += b;
    }

    sort(soma.rbegin(), soma.rend());
    
    int s = 0;
    for(int i = 0; i < min(n, k); i++){
        s+= soma[i];
    }        

    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

