#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    map<pair<int,char>,int> freq;
    vector<int> num(n);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        char b; cin >> b;
        num[i]=a;
        pair<int,char> aux={a,b};
        freq[aux]++;
    }
    int res=0;
    for(auto u:num){
        pair<int,char> a1={u,'D'};
        pair<int,char> a2={u,'E'};
        if(freq[a1]<freq[a2]) swap(a1,a2);
        freq[a1]-=(freq[a1]-freq[a2]);
        res+=(freq[a1]+freq[a2])/2;
        freq[a1]=0;
        freq[a2]=0;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

