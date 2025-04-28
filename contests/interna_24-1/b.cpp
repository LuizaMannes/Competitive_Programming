#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k; cin >> n >> k;
    vector<int> ar(3);
    int chore=0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        ar[a%3]++;
        chore^=(a%3);
    }

    if(k==0){
        cout << (chore ? "Julia" : "Giovana") << endl;
        return;
    }

    if(ar[0]==0){
        if((ar[1]%2==0) && (ar[2]%2==0)){
            cout << (k & 1 ? "Julia" : "Giovana") << endl;   
        }else{
            if((ar[1]%2)!=(ar[2]%2)) cout << "Julia" << endl; // 0, 1
            else if (ar[1]&1) cout << (k&1 ? "Giovana" : "Julia") << endl;
            //else cout << (k & 1 ? "Giovana" : "Julia") << endl; // 0, 0 ou 1, 1
        }
    } else {
        if((ar[1]%2)!=(ar[2]%2)) cout << "Julia" << endl;
        else cout << "Giovana" << endl;
    }


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

