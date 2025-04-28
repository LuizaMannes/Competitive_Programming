#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=2e5+5;

vector<int> adj[nmax];
vector<int> sub(nmax);

void dfs(int u,int p){
    for(auto v: adj[u]){
        if(p!=v){
            dfs(v,u);
            sub[u]+=sub[v]+1;
        }
    }
}

void solve() {
    int n; cin >> n;
    
    for(int i=2;i<=n;i++){
        int a;cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout << sub[i] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

