#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF=1e9;

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    int aux=0;
    int res=INF;
    int eita=0;
    for(int i=0;i<n;i++) cin >> ar[i];
    for(int i=0;i<n;i++){
        aux+=ar[i];
        int mds=0;
        int som=0;
        eita=i+1;
        for(int j=i+1;j<n;j++){
            som+=ar[j]; 
            mds++;
            if(som==aux){
                eita=max(eita,mds);
                som=0;
                mds=0;
            }
            else if(som>aux || j==n-1){
                eita=INF;
                break;
            }
        }
        res=min(res,eita);
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

