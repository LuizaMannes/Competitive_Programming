#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+5;

vector<int> adj[mx];
vector<int> jda[mx];
vector<int> ts;
vector<int> vis(mx);
vector<int> cor(mx);

void dfs(int u){
    vis[u]++;

    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    ts.push_back(u);
}

int evil_dfs(int u, int n){
    vis[u]++;
    cor[u]=n;

    for(auto v: jda[u]){
        if(!vis[v]){
            evil_dfs(v,n);
        }else{
            if(cor[v]!=n) return v;
        }
    }
    return 0;
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

    int a=0;
    while(ts.size()){
        int b=ts.back();
        
        ts.pop_back();

        if(!vis[b]){
            int c=evil_dfs(b,++a);
            if(c){
                cout << "NO" << endl;
                cout << b << " " << c << endl;
                return;
            }
        }
    }

    for(int i=1;i<n;i++){
        if(cor[i]!=cor[i+1]){
            cout << "NO" << endl;
            cout << i << " " << i+1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

