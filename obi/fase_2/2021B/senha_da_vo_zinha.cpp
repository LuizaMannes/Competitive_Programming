#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

void solve() {
    int n,m,k;cin >> n >> m >> k;

    string s;cin >> s;
    
    vector<string> ar(m);
    for(int i=0;i<m;i++){
        cin >> ar[i];
        sort(ar[i].begin(),ar[i].end());
    }

    int p;cin >> p;
    p--;

    int aux=m-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='#'){
            string j=ar[aux];
            s[i]=j[p%k];
            p/=k;
            aux--;
        }
    }

    cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

