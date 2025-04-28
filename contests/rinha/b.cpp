#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m; cin >> n >> m;
    vector<int> ar(n);
    set<int> set;
    vector<int> freq(m+1);
    for(int i=0;i<n;i++){
        cin >> ar[i];
        freq[ar[i]]++;
        set.emplace(freq[ar[i]]);
    }
    int p=*set.rbegin();
    int a=0;
    for(int i=0;i<n;i++){
        if(p==freq[ar[i]]){
            a=ar[i];
            break;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(ar[i]!=a) res++;
    }
    cout << res << endl;
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

