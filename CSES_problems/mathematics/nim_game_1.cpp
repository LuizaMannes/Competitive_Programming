#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int chore=0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        chore^=a;
    }
    cout << (chore? "first" : "second") << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

