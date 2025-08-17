#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    stack<int> s;
    vector<int> next(n);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && ar[i] < ar[s.top()]){
            next[s.top()] = i + 1;
            s.pop();
        }

        s.emplace(i);
    }
    
    for(int i = 0; i < n; i++) cout << next[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

