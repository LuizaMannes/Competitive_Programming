#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=505;

int vis[nmax][nmax];
vector<pair<int,int>> pos={{1,0},{-1,0},{0,1},{0,-1}};
int arr[nmax][nmax];
int n,f;

bool nao_pode(int i, int j, int u, int v){
    return i+u<0 || i+u>n-1 || j+v<0 || j+v>n-1; 
}

void dfs(int i,int j){
    vis[i][j]++;
    for(auto [u,v]:pos){
        if(nao_pode(i,j,u,v)) continue;  
        if(vis[i+u][j+v]==0 && arr[i+u][j+v]<=f){
            dfs(i+u,j+v);
        }
    }
}

void solve() {
    cin >> n >> f;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin >> c;
            int s=c-'0';
            arr[i][j]=s;
        }
    }

    if(arr[0][0]<=f) dfs(0,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=0) cout << '*';
            else cout << arr[i][j];
        }
        cout << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


