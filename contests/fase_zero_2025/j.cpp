#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> ar(n);
    stack<int> s;
    for(int i = 0; i < n; i++) cin >> ar[i];

    for(int i = 0; i < n; i++) ar.push_back(ar[i]);

    vector<int> nextSmaller(n, -1);

    for (int i = 0; i < 2 * n; i++) {
        while (!s.empty() && ar[i] < ar[s.top()] + abs(i - s.top()) * k) {
            nextSmaller[s.top() % n] = (i % n); 
            s.pop(); 
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        cout << nextSmaller[i] + 1 << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

