#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,l; cin >> n >> l;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    sort(ar.begin(),ar.end());
    reverse(ar.begin(),ar.end());
    int res=0;
    for(int i=0;i<n;i++){
        int aux=100-ar[i];
        if(l>=aux){
            l-=aux;
            res++;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

