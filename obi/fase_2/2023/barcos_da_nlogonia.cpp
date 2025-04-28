#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = tuple<int,int,int>;

const int mx = 1e5+5;
const int L = 18;

int pai[mx];
int sz[mx];
vector<pair<int,int>> adj[mx];
int depth[mx];
int up[mx][L];
int ma[mx][L];

// DSU //

int find(int u){
    if(pai[u]==u) return u;
    return find(pai[u]);
}

bool unite(int u, int v){
    int pu=find(u);
    int pv=find(v);

    if(pu!=pv){
        if(sz[pv]>sz[pu]) swap(pu,pv);
        sz[pu]+=sz[pv];
        pai[pv]=pu;
    
        return true;
    }

    return false;
}

// BL //

void dfs(int u, int p){
    for(int i=1;i<L;i++){
        up[u][i] = up[up[u][i-1]][i-1];
        ma[u][i] = min(ma[u][i-1],ma[up[u][i-1]][i-1]);
    }
    
    for(auto [w,v] :adj[u]){
        if(v!=p){
            up[v][0]=u;
            ma[v][0]=w;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
}

void bl(){
    
    up[1][0] = 1;
    ma[1][0] = 0;
    depth[1] = 1;

    dfs(1,0);
}

// LCA //

int lca(int x, int y){

    int ans=1e9;

    if(depth[x]<depth[y]) swap(x,y);

    int k = depth[x]-depth[y];
    if(k){
        for(int i=0;i<L;i++){
            if(k & (1<<i)){
                ans=min(ma[x][i],ans);
                x=up[x][i];
            }
        }
    }
    if(x==y) return ans;

    for(int i=L-1;i>=0;i--){
        if(up[x][i]!=up[y][i]){
            ans=min({ans,ma[x][i],ma[y][i]});
            x=up[x][i]; 
            y=up[y][i];
        }
    }
    return min({ans,ma[x][0],ma[y][0]});
}


void solve() {
    int n,b;cin >> n >> b;

    for(int i=1;i<=n;i++){
        pai[i]=i;
        sz[i]=1;
    }

    vector<T> edges;
    for(int i=0;i<b;i++){
        int u,v,w; cin >> u >> v >> w;
        edges.emplace_back(w,u,v);
    }
    sort(edges.rbegin(),edges.rend());

    for(auto [w,u,v]:edges){
        if(unite(u,v)){
            adj[u].emplace_back(w,v);
            adj[v].emplace_back(w,u);
        }
    }
    
    bl();

    int c; cin >> c;

    for(int i=0;i<c;i++){
        int x,y; cin >> x >> y;
        cout << lca(x,y) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

