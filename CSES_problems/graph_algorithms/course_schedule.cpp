#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+5;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> tp;
vector<int> vis(mx);
int cor[mx];

void dfs(int u){
    vis[u]++;

    for(auto v:adj[u]){
        if(!vis[v]) dfs(v);
    }

    tp.push_back(u);
}

bool sdf(int u,int c){
    vis[u]++;
    cor[u]=c;
    for(auto v:jda[u]){
        if(!vis[v]){
            if(sdf(v,c)) return true;
        }else{
            if(cor[v]==cor[u]) return true;
        }
    }

    return false;
}

void solve() {
    int n,m;cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        jda[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }

    for(int i=1;i<=n;i++) vis[i]=0;

    vector<int> ans = tp;
    reverse(ans.begin(),ans.end());
    
    bool tem=false;
    int c=0;
    while(tp.size()){
        int a=tp.back();
        tp.pop_back();

        if(!vis[a]){
            if(sdf(a,++c)) tem=true;
        }
    }

    if(!tem){
        for(auto c:ans) cout << c << ' ';
        cout << endl;
    }else cout <<"IMPOSSIBLE" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

