#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s; cin >> s;

    map<char,int> freq;
    int res=0;
    for(int i=0;i<n;i++){
        if(!freq[s[i]]) res+=n-i; 
        freq[s[i]]++;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

