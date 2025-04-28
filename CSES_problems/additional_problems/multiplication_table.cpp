#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    
    int l = 0, r = n * n, res = 0, meio = (n * n) / 2 + 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        
        int count = 0, f = -1;
        for(int i = 1; i <= n; i++){
            count += min(mid / i, n); 
            if(mid % i == 0 && mid / i <= n ) f++;
        }

        if(count >= meio && count - f <= meio){
            res = mid;
            break;
        }
        if(count > meio){
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

