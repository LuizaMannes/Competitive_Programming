#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

bool check(int mid, __int128_t h, vector<int> &cool, vector<int> &ata){
    for(int i=0;i<ata.size();i++){
        h-=(__int128_t) mid/cool[i]*ata[i];
        if(h<=0) return true;
    }
    return false;
}

void solve() {
    int h,n; cin >> h >> n;
    vector<int> ata(n);
    vector<int> cool(n);
    for(int i=0;i<n;i++){
        cin >> ata[i];
        h-=ata[i];
    }
    for(int i=0;i<n;i++) cin >> cool[i];
    
    if(h<=0){
        cout << 1 << endl;
        return;
    }
    __int128_t v=h;
    int l=1;
    int r=1e18;
    int res=0;
    while(l<=r){
        int mid=(l+r) >> 1;
        if(check(mid-1,v,cool,ata)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

