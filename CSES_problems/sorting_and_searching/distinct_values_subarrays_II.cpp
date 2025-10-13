#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, res = n, cnt = 0;;
    map<int,int> f;
    for(int i = 0; i < n; i++){
        if(f[ar[i]] == 0) cnt++;
        f[ar[i]]++;
        while(cnt > k){
            f[ar[l]]--;
            if(f[ar[l]] == 0) cnt--;
            l++;
        }

        res += i - l;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


