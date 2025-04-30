#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    vector<int> vida(n);
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) cin >> vida[i];
    for(int i=0;i<n;i++){
        int a;cin >> a;
        pos[abs(a)]+=vida[i];
    }
    int shots=k;
    for(int i=1;i<=n;i++){
        shots-=pos[i];
        if(shots<0){
            cout << "NO" << endl;
            return;
        }
        shots+=k;
    }
    cout << "YES" << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

