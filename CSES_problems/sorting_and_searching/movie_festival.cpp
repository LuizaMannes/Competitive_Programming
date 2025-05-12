#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ar[i] = pair<int,int> (b, a);
    }

    sort(ar.begin(), ar.end());

    int last = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(ar[i].second >= last){
            res++;
            last = ar[i].first;
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

