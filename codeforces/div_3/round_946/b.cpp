#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    set<char> s;
    string t; cin >> t;
    for(int i=0;i<n;i++){
        s.emplace(t[i]);
    }
    vector<char> v;
    for(auto c:s) v.push_back(c);
    map<char,char> m;
    
    int l=0;
    int r=v.size()-1;
    while(l<r){
        m[v[l]]=v[r];
        m[v[r]]=v[l];
        l++;
        r--;
    }
    for(int i=0;i<n;i++){
        if(m[t[i]]!=0)cout << m[t[i]];    
        if(m[t[i]]==0) cout << t[i];
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

