#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int mid,vector<int> &ar,int m){
    int res=0;
    for(int i=0;i<ar.size();i++){
        if(mid<ar[i]){
            res+=ar[i]-mid;
        }
    }
    return res<=m;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    int l=0;
    int r=1e9+10;
    int res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid,ar,m)){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

