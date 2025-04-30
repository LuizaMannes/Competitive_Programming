#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF=1e9;

void solve() {
    int n,m;cin >> n >> m;

    vector<vector<char>> ar(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    int a=INF;
    int b=INF;
    int c=0;
    int d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ar[i][j]=='#'){
                a=min(a,i);
                b=min(b,j);
                c=max(c,i);
                d=max(d,j);
            }
        }
    }
    cout << (a+c)/2+1 << " " << (b+d)/2+1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

