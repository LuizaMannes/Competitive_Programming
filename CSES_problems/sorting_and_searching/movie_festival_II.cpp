#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        ar[i] = pair<int,int> (a, b);
    }

    sort(ar.begin(), ar.end());
    
    multiset<int> s;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(s.size() < k) s.emplace(ar[i].second);
        else{
            if(ar[i].first >= *s.begin()){
                s.erase(s.begin());
                s.emplace(ar[i].second);
                res++;
            }
            else{
                auto u = s.end();
                u--;
                if(ar[i].second < *u){
                    s.erase(u);
                    s.emplace(ar[i].second);
                }
            }
        }
    }

    cout << k + res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

