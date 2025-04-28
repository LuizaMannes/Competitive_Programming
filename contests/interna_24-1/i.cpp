#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int cont=1;
    vector<int> estrela(n);
    for(int i=0;i<n;i++) cin >> estrela[i];
    int res=estrela[0];
    int aux=estrela[0];
    for(int i=1;i<n;i++){
        res+=estrela[i];
        if(aux & estrela[i]){
            cont++;
            aux=estrela[i];
        }else aux|=estrela[i];
    }
    
    cout << res << " " << cont << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

