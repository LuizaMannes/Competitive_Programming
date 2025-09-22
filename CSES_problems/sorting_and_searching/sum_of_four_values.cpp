#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, x; cin >> n >> x;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
    
    map<int, pair<int,int>> m;
    for(int i = n - 1; i >= 0; i--){
        for(int j = i - 1; j >= 0; j--){
            int y = x - ar[i] - ar[j];
            if(m.find(y) != m.end()){
                cout << m[y].first + 1 << " " << m[y].second + 1 << " " << i + 1 << " " << j + 1 << endl;
                return;
            }
        }

        for(int j = i + 1; j < n; j++) m[ar[i] + ar[j]] = {i, j};
    }
    cout << "IMPOSSIBLE" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


