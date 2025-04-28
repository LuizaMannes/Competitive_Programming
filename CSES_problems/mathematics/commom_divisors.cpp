#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1e6;

void solve() {
    int n;cin >> n;

    vector<int> freq(nmax+5);

    for(int i=0;i<n;i++){
        int a;cin >> a;
        freq[a]++;
    }

    for(int i=nmax;i>=1;i--){
        int count=0;
        for(int j=i;j<=nmax;j+=i) count+=freq[j];
        if(count>=2){
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

