#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int p2=0;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        while(a%2==0){
            a>>=1;
            p2++;
        }
    }
    vector<int> pos;
    for(int i=1;i<=n;i++){
        int a=i;
        int cont=0;
        while(a%2==0){
            a>>=1;
            cont++;
        }
        pos.push_back(cont);
    }
    sort(pos.begin(),pos.end());
    reverse(pos.begin(),pos.end());
    int res=0;
    for(int i=0;i<pos.size();i++){
        if(p2>=n){
            cout << res << endl;
            return;
        }
        p2+=pos[i];
        res++;
    }
    cout << -1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

