#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    set<int> ar;
    int soma=0;
    int res=0;
    for(int i=1;i<=n;i++){
        int a;cin >> a;
        ar.emplace(a);
        soma+=a;
        int aux=*ar.rbegin();
        if(soma-aux==aux) res++;
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

