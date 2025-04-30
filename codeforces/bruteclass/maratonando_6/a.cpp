#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,x,y;cin >> n >> x >> y;
    map<pair<int,int>, int> freq;

    vector<int> ar(n);
    for(auto &i : ar) cin >> i;

    int res=0;
    for(auto a: ar){
        int ax=a%x, ay=a%y;
        pair<int,int> c={ax,ay};

        int xx=(x-ax)%x;
        pair<int,int> b={xx,ay};
        if(freq[b])res+=freq[b];

        freq[c]++;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

