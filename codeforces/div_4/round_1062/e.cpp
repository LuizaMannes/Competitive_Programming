#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar.begin(), ar.end());

    int l = 0, r = 1e9 + 1;
    set<int> res;
    while(l <= r){
        int mid = (l + r) / 2;
        
        set<int> a;
        int last = -mid;
        for(int i = 0; i < n; i++){
            if(a.size() == k) break;
            int ll = last + mid, rr = ar[i] - mid;
            while(ll <= rr and a.size() < k){
                a.emplace(ll);
                ll++;
            }
            last = ar[i];
        }

        if(a.size() < k){
            int ll = last + mid, rr = x;
            while(ll <= rr and a.size() < k){
                a.emplace(rr);
                rr--;
            }
        }

        //cout << mid << endl;
        if(a.size() == k){
            l = mid + 1;
            res = a;
        }else r = mid - 1;
    }

    for(auto i: res) cout << i << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

