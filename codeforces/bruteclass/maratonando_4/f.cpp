#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(vector<int> &arr,int mid){
    int aux = 0;
    int soma = 0;
    for(int i=0;i<arr.size();i++){
        soma+=arr[i];
        if(soma > mid){
            soma = arr[i];
            aux++;
        }

    }
    return aux <3;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i;i<n;i++) cin >> arr[i];
    int l=0;
    int r=1e18;
    int res=0;
    while(l<=r){
       int mid = (l+r) >> 1;
       if(check(arr,mid)){
            res = mid;
            r = mid-1;
       }else{
            l = mid + 1; 
       }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
