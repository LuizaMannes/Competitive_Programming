#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

vector<int> pref(19);

void solve() {
    int k; cin >> k;

    int l = 0, r = 1e18, res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;

        int count = 0, n = mid, sum = 0, d = 1;
        
        vector<int> ar;
        while(n){
            count++;
            ar.push_back(n % 10);
            n /= 10;
        }
        reverse(ar.begin(), ar.end());
        //cout << "mid " << mid << endl;
        //cout << "count " << count << endl;

        for(int i = 0; i < count - 1; i++) d *= 10;

        sum = (mid - d) * count + pref[count - 1];
        //cout << "sum " << sum << endl;
        //cout << "d " << d << endl;
    
        for(int i = 0; i < ar.size(); i++){
            sum++;
            if(sum == k){
                res = ar[i];
                break;
            }
        }

        if(res != -1) break;

        if(sum > k) r = mid - 1;

        if(sum < k) l = mid + 1;
        
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int d = 1;
    for(int i = 1; i <= 18; i++){
        pref[i] = 9 * d * i + pref[i - 1];
        d *= 10;
    }

    int tc;cin >> tc; while(tc--) solve();
}

