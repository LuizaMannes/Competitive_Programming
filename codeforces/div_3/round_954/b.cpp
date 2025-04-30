#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n,m; 

bool pode(int a,int b){
    return a>=0 && b>=0 && a<n && b<m;
}

void solve() {
    cin >> n >> m;
    
    vector<pair<int,int>> pos={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> ar(n,vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int maior=-1;
            for(auto [x,y]:pos){
                if(pode(i+x,j+y)) maior=max(maior,ar[i+x][j+y]);
            }
            if(maior<ar[i][j]) ar[i][j]=maior;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

