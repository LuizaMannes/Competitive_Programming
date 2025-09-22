#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    int l = 0, res = n;
    map<int,int> f;
    for(int i = 0; i < n; i++){
        f[ar[i]]++;
        while(f[ar[i]] > 1){
            f[ar[l]]--;
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

