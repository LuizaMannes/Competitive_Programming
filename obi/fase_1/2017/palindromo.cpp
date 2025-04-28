#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int res=0;
    int aux=0;
    for(int i=0;i<n-1;i=aux){
        int l=i;
        int r=n-1;
        aux=r;
        while(l<=r){
            if(s[l]!=s[r]){
                if(i==1) cout << "aqui" << endl;
                aux=r;
                r--;
                l=i;
                continue;
            }
            l++;
            r--; 
        }
        cout << "l: " << l << " r: " << r << endl;
        cout << "aux: " <<  aux << endl;
        res++;
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

