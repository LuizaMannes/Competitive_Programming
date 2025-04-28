#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,q; cin >> n >> q;
    vector<int> ar(n);
    vector<int> pre(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    int aux=0;
    for(int i=0;i<n;i++){
        aux=gcd(aux,ar[i]);
        pre[i]=aux;
    }
    int r=n-1;
    while(q--){
        int a,b; cin >> a >> b;
        if(a==1){
            int t=gcd(pre[r],b);
            pre.push_back(t);
            r++;
        }if(a==2){
            r-=b;
            while(b--) pre.pop_back();
        }if(a==3){
            if(pre[r]%b==0) cout << "SIM" << endl;
            else cout << "NAO" << endl;
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

