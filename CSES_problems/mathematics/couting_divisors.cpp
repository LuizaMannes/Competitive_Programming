#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1e6+5;

vector<int> divi(nmax);

void count(){
    for(int i=1;i<nmax;i++){
        for(int j=i;j<nmax;j+=i){
            divi[j]++;
        }
    }
}

void solve() {
    int n;cin >> n;
    
    cout << divi[n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    count();
    int tc;cin >> tc; while(tc--) solve();
}

