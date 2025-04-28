#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T = tuple<int,int,int>;

const int mx=1e5+5;

int pai[mx];
int sz[mx];
int soma=0;


int find(int u){
    if(pai[u]==u) return u;
    return find(pai[u]);
}

void unite(int a,int b,int w){
    a=find(a);
    b=find(b);

    if(b!=a){
        if(sz[a]<sz[b]) swap(a,b);

        sz[a]+=sz[b];
        pai[b]=a;
        soma+=w;
    }
}

void solve() {
    int n,m;cin>> n >> m;
    
    vector<T> edges(m);

    for(int i=1;i<=n;i++){
        sz[i]=1;
        pai[i]=i;
    }

    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        edges.emplace_back(w,u,v);
    }

    sort(edges.begin(),edges.end());

    for(auto [w,a,b]:edges){
        unite(a,b,w);
    }

    for(int i=1;i<n;i++){
        if(find(i)!=find(i+1)){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << soma << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

