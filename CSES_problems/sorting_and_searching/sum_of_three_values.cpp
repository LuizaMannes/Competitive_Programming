#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x; cin >> n >> x;

    vector<pair<int, int>> ar(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ar[i] = {a, i};
    }
    sort(ar.begin(), ar.end());
    
    vector<int> res;
    bool ok = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = n - 1;
        while(l != r){
            auto [a, ii] = ar[i];
            auto [b, ll] = ar[l];
            auto [c, rr] = ar[r];
            if(a + b + c == x && l != i && r != i){
                res.push_back(ii + 1);
                res.push_back(rr + 1);
                res.push_back(ll + 1);
                ok = 1;
                break;
            }

            if(a + b + c > x) r--;
            else l++;
        }

        if(ok) break;
    }

    sort(res.begin(), res.end());

    if(ok) cout << res[0] << " " << res[1] << " " << res[2] << endl;
    else cout << "IMPOSSIBLE" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

