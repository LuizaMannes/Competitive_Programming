#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF=1e9;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    vector<int> ar(n);
    for(int i=0;i<n;i++) ar[i]=s[i]-'0';
    
    int res=INF;
    for(int i=0;i<n-1;i++){
        vector<int> a(n,1);
        for(int j=0;j<n;j++){
            if(j==i+1) continue;
            a[j]=ar[j];
        }
        a[i]=ar[i]*10+ar[i+1];
        int cont=0;
        int maxi=0;
        int mini=INF;
        for(int i=0;i<n;i++){
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
            if(a[i]==0){
                cont=0;
                break;
            }
            if(a[i]>1) cont+=a[i];
        }
        if(maxi==1 && mini==1) cont=1;
        res=min(res,cont);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}
