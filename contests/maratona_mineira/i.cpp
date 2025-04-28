#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5+5;

int pos[mx];
int f[mx];

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        f[a[i]]++;
    }
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        //cout << "a[i] " << a[i] << endl;
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i] % j == 0){
                int x = j;
                int y = a[i]/j;
                //cout << x << ' ' << y << endl;
                if(f[x] != 0) pos[a[i]] = max(pos[a[i]], pos[x]);
                if(f[y] != 0 && x != y) pos[a[i]] = max(pos[a[i]], pos[y]);
            }
        }
        pos[a[i]]++;
    }

    int ans = 0;
    for(int i = 1; i < mx; i++) ans = max(ans, pos[i]);
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

