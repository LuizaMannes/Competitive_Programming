#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, t; cin >> n >> t;

    if(t == 0){
        cout << n << endl;
    }
    
    if(t == 1){
        cout << n * (n-1) << endl;
    }

    if(t == 2){
       int soma = 0;
       for(int i=1;i<=n-1;i++) soma+= i * (n-i-1); 
       cout << soma << endl; 
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

