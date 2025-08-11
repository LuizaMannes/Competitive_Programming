#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 21;
int n;
vector<int> ar(mx);

int res(int i, int s1, int s2){
    if(i >= n) return abs(s1 - s2);

    int res1 = res(i + 1, s1 + ar[i], s2);
    int res2 = res(i + 1, s1, s2 + ar[i]);

    return min(res1, res2);
}

void solve() {
    cin >> n;

    for(int i = 0; i < n; i++) cin >> ar[i];
    
    cout << res(0, 0, 0) << endl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

