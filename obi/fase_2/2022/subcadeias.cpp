#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            int l=i;
            int r=j;
            int aux=r-l+1;
            while(l<=r){
                if(s[l]!=s[r]){
                    aux=0;
                    break;
                }
                l++;
                r--;
            }
            res=max(aux,res);
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

