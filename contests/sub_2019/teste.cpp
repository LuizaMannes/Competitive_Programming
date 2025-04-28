#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'


void solve() {
    int c;cin >> c;
    int ar[c+5];
    for(int i=0;i<=c;i++){
        ar[i]=i; 
    }
    map<int,int> mp;
    set<int> set;
    for(int i=0;i<=c;i++){
        int aux=0;
        int a=ar[i];
        while(a){
            if(a&1) aux++;
            a>>=1;
        }
        set.emplace(aux);
        mp[aux]++;
    }
    int res=0;
    for(auto c:set){
        if(mp[c]%2!=0) res++;
    }
    cout << res << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

