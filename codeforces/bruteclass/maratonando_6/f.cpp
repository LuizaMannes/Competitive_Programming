#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    map<int,char> a;
    map<int,int> freq;

    for(int i=0;i<n;i++) a[i]='a';

    for(int i=0;i<n;i++){
        int b;cin >> b;
        if(freq[b]) a[b]++; 
        freq[b]++;
        cout << a[b];
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

