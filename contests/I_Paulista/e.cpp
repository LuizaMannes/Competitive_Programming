#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, d; cin >> n >> d;

    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ar[i] = {a, b};
    }

    sort(ar.begin(), ar.end());

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        v[i] = ar[i - 1].second + v[i - 1];
    }

    int res1 = 0, l = 0, r = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && ar[j].first - ar[i].first <= d){
            if(res1 <= v[j + 1] - v[i]){
                res1 = v[j + 1] - v[i];
                l = i; r = j;
            }
            j++;
        }
    }


    vector<pair<int,int>> ar2;
    for(int i = 0; i < n; i++){
        if(i >= l && i <= r) continue;
        ar2.push_back(ar[i]);
    }

    vector<int> v2(ar2.size() + 1);
    for(int i = 1; i <= ar2.size(); i++){
        v2[i] = ar2[i - 1].second + v2[i - 1];
    }

    int res2 = 0;
    for(int i = 0, j = 0; i < ar2.size(); i++){
        while(j < ar2.size() && ar2[j].first - ar2[i].first <= d){
            res2 = max(res2, v2[j + 1] - v2[i]);
            j++;
        }
    }

    cout << res1 << " " << res2 << endl;
    cout << res1 + res2 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

