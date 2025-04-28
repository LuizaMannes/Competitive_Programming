#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=505;

char adj[mx][mx];
int n,m;
vector<pair<int,int>> pos={{0,1},{0,-1}};
int vis[mx][mx];

bool nao_pode(int i,int j, int u, int v){
    return i+u<0 || i+u>n-1 || j+v<0 || j+v>m-1 || adj[i+u][j+v]=='#';
}

void dfs(int i, int j){
    vis[i][j]++;
    if(adj[i+1][j]!='#' && vis[i+1][j]==0 && i+1<n) dfs(i+1,j);
    else if(adj[i+1][j]=='#'){
        for(auto [u,v]:pos){
            if(nao_pode(i,j,u,v)) continue;
            if(vis[i+u][j+v]==0){
                dfs(i+u,j+v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    int x=0;
    int y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;cin >> a;
            if(a=='o'){
                x=i;
                y=j;
            }
            adj[i][j]=a;
        }
    }
    dfs(x,y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]) cout << 'o';
            else cout << adj[i][j];
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

