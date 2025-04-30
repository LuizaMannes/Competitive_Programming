#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF=1e18;

int check(int mid, vector<int> &ar, int c){
    int aux=c;
    for(int i=0;i<ar.size();i++){
        aux-=(mid*2+ar[i])*(mid*2+ar[i]);
        if(aux<0) return INF;
    }
    return aux;
}

void solve() {
    int n,c;cin >> n >> c;
    vector<int> ar(n);
    
    for(int i=0;i<n;i++) cin >> ar[i];

    int l=0;
    int r=1e9+5;
    int res=0;
    while(l<=r){
        int mid=(l+r) >> 1; 
        int a=check(mid,ar,c);
        if(a==0){
            res=mid;
            break;
        }
        if(a==INF){
            r=mid-1;
        }else l=mid+1;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

