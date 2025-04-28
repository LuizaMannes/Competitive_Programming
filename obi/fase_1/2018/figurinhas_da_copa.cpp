#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m,c;cin >> n >> m >> c;
    vector<int> car(m);
    map<int,int> freq;
    for(int i=0;i<m;i++) cin >> car[i];
    for(int i=0;i<c;i++){
        int a;cin >> a;
        freq[a]++;
    }
    int res=0;
    for(auto c:car) {
        if(freq[c]==0) res++;
    }
    cout << res << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

