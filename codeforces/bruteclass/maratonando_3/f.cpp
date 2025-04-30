#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];
    int neg=0;
    for(int i=0;i<n;i++){
        if(ar[i]==0){
            cout << '0' << endl;
            return;
        }
        if(ar[i]<0) neg++;
    }
    if(neg & 1){
        cout << '0' << endl;
    }else{
        cout << '1' << endl;
        cout << '1' << " 0" << endl;
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        solve();
    }
}

