#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k, q;cin >> n >> k >> q;
    vector<int> dist(k+1);
    vector<int> min(k+1);
    for(int i=0;i<k;i++) cin >> dist[i+1];
    for(int i=0;i<k;i++) cin >> min[i+1];
    for(int j=0;j<q;j++){
        int d;cin >> d;
        int res=0;
        int l=0,r=k;
        while(l<=r){
            int mid=(l+r)>>1;
            if(dist[mid]>d){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(dist[r]==d){
            cout << min[r] << ' ';
            continue;
        }
        r++;
        res=min[r-1]+(d-dist[r-1])*(min[r]-min[r-1])/(dist[r]-dist[r-1]);
        cout << res << ' ';
    }
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--) solve();
}

