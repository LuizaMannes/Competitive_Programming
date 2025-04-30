#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)cin >> ar[i];
    int res=0;
    map<tuple<int,int,int>,int> t;
    map<pair<int,int>,int> p1,p2,p3;
    for(int i=0;i<n-2;i++){
        pair<int,int> a={ar[i],ar[i+1]},
                      b={ar[i],ar[i+2]}, 
                      c={ar[i+1],ar[i+2]};
        tuple<int,int,int> t1={ar[i],ar[i+1],ar[i+2]};
        res+=p1[a];
        res+=p2[b];
        res+=p3[c];
        res-=3*t[t1];
        t[t1]++;
        p1[a]++;
        p2[b]++;
        p3[c]++;
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

