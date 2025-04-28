#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

bool check(int mid, vector<int> &ar, int c){
    int aux=1;
    int soma=0;
    for(int i=0;i<ar.size();i++){
        soma += ar[i];
        if(soma>mid){
            if(ar[i]>mid) return false;
            aux++;
            soma=ar[i];
        }
    }
    if(soma>mid) aux++;
    return aux<=c;
}

void solve() {
    int n, c, t; cin >> n >> c >>t;
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    int l=0;
    int r=1e15;
    int ans=0;
    while(l<=r){
        int mid=(l+r) >> 1;
        if(check(mid, ar, c)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    if(ans%t!=0) cout << ans/t+1 << endl;
    else cout << ans/t << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
