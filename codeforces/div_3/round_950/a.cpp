#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m;cin >> n >> m;
    string s;cin >> s;
    map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    int res=0;
    for(int i=0;i<7;i++){
        if(m-freq[i+'A']>=0) res+=m-freq[i+'A'];
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

