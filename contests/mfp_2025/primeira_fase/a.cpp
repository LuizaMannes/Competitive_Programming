#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    vector<int> ar(n), freq(m + 1);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        freq[ar[i]]++;
    }

    for(int i  = 0; i < m; i++){
        cout << n - freq[i] << " ";
        freq[i + 1] += freq[i]; 
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

