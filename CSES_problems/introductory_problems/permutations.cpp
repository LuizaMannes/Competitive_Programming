#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);

    if(n<=3 && n>1){
        cout << "NO SOLUTION" << endl;
        return;
    }

    int a=n/2+1;
    int cont=1;
    for(int i=0;i<n-1;i+=2){
        ar[i]=cont; 
        ar[i+1]=n-cont+1;
        cont++;
    }
    ar[n-1]=a;
    if(n==4) swap(ar[0],ar[n-2]);
    else swap(ar[0],ar[n-1]);

    for(auto c: ar) cout << c << ' ';
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

