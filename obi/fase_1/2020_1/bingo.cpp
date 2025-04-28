#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k ,u; cin >> n >> k >> u;
    vector<set<int>> a(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int b; cin >> b;
            a[i].emplace(b);
        }
    }
    vector<int> res;
    bool acaba=false;
    for(int i=0;i<u;i++){
        int c;cin >> c;
        for(int j=0;j<n;j++){
            a[j].erase(c);
            if(a[j].size()==0){
                res.push_back(j+1);
                acaba=true;
            }
        }
        if(acaba) break;
    }
    for(auto c:res) cout << c << ' ';
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

