#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1005;

int vis[nmax][nmax];
vector<pair<int,int>> pos={{1,0},{-1,0},{0,1},{0,-1}};
char arr[nmax][nmax];
int n,m;
int res=0;

bool nao_pode(int i, int j, int u, int v){
    return i+u<0 || i+u>n-1 || j+v<0 || j+v>m-1; 
}

void dfs(int i,int j){
    vis[i][j]++;
    for(auto [u,v]:pos){
        if(nao_pode(i,j,u,v)) continue;  
        if(vis[i+u][j+v]==0 && arr[i+u][j+v]=='.'){
            dfs(i+u,j+v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin >> c;
            arr[i][j]=c;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.' && vis[i][j]==0){
                dfs(i,j);
                res++;
            }
        }
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}



