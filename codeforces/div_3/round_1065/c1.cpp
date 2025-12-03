#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int pa = 0, pb = 0;
    for(int i = 0; i < n; i++){
        pa ^= a[i];
        pb ^= b[i];
    }

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(!pa){
                if(b[i] != a[i]){
                    pa ^= 1;
                    pb ^= 1;
                }
            }
        }
        else{
            if(!pb){
                if(a[i] != b[i]){
                    pa ^= 1;
                    pb ^= 1;
                }
            }
        }
    }

    if(pb and !pa) cout << "Mai" << endl;
    else if(pa and !pb) cout << "Ajisai" << endl;
    else cout << "Tie" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

