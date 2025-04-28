#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1e4;
const int INF=1e9;

char adj[nmax][nmax];
int dist[nmax][nmax];
vector<pair<int,int>> pai[nmax];
int n,m;
vector<pair<int,int>> pos={{1,0},{-1,0},{0,1},{0,-1}};
char ans[nmax][nmax];
bool mdsqsaco=false;
bool chegou=false;
queue<pair<int,int>> q;

bool borda(int i, int j){
    return i==0 || i==n-1 || j==0 || j==m-1;
}

bool nao_pode(int i, int j, int u, int v){
    return i+u<0 || i+u>n-1 || j+v<0 || j+v>m-1; 
}

string nam(int x, int y){
   string res="";
   int a=x;
   int b=y;
   res+=ans[a][b];
   while (adj[a][b]!='A') {
       int aux = pai[a][b].first;
       b = pai[a][b].second;
       a = aux;
       res+=ans[a][b];
   }
   reverse(res.begin(),res.end());
   res.erase(0,1);
   return res;
}

void bfs(int i,int j) {
    if(mdsqsaco){
        dist[i][j] = 0;
        q.emplace(i,j);
    }
    while (!q.empty()) {
        pair<int,int> u = q.front();
        int a = u.first;
        int b = u.second;
        q.pop();
        for (auto [u,v] : pos) {
            if(nao_pode(a,b,u,v) || adj[a+u][b+v]=='#') continue;
            if (dist[a+u][b+v] > dist[a][b]+1) {
                dist[a+u][b+v] = dist[a][b] + 1;
                q.emplace(a+u,b+v);
                if(mdsqsaco){
                    
                    if(u==1) ans[a+u][b+v]='D';
                    if(u==-1) ans[a+u][b+v]='U';
                    if(v==1) ans[a+u][b+v]='R';
                    if(v==-1) ans[a+u][b+v]='L';

                    pai[a+u][b+v].first=a;
                    pai[a+u][b+v].second=b;
                    
                    if(borda(a+u,b+v)){
                        cout << "YES" << endl;
                        cout << dist[a+u][b+v] << endl;
                        cout << nam(a+u,b+v) <<  endl;
                        chegou=true;
                        return;
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<pair<int,int>> monstros;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=INF;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin >> c;
            adj[i][j]=c;
            if(c=='M'){
                q.emplace(i,j);
                dist[i][j]=0;
            }
        }
    }

    bfs(0,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pai[i].emplace_back(-1,-1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='A'){
                if(borda(i,j)){
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return;
                }
                mdsqsaco=true;
                bfs(i,j); 
            }
        }
    }

    if(!chegou) cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

