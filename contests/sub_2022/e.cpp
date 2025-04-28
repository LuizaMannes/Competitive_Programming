#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    map<int,int> freq;
    for(auto &i:ar){
        cin >> i;
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        freq[ar[i]]++;
        if(freq[ar[i]+1]){
            freq[ar[i]+1]--;
            continue;
        }
        ans++;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

