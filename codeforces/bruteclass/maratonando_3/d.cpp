#include <bits/stdc++.h>

using namespace std;
#define int long long 

bool check(int mid, vector<int>& ar, int vida){
    int resp = 0;
    for(int i=0;i < ar.size();i++){       
         if(i<ar.size()-1 && mid > ar[i+1] - ar[i]){
            resp+= ar[i+1] - ar[i];
        } else {
            resp+=mid;
        }
    }

    return resp>=vida;

}

void solve() {
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int l=1;
    int r=1e18;
    int ans=0;
    while(l<=r){
        int mid=(l+r) >> 1;
        if(check(mid, arr, k)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout <<  ans << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--){
         solve();
    }
}

