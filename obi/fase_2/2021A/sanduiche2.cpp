#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m; cin >> n >> m;

    vector<pair<int,int>> r(m);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        a--; b--;
        r[i]={a,b};
    }

    int res=0;
    for(int i=1;i<(1<<n);i++){
        bool ok = true;
        for(auto [a,b] : r){
            int ba = 1 << a;
            int bb = 1 << b;

            if((i & ba) && (i & bb)) ok = false;
        }

        if(ok) res++;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

