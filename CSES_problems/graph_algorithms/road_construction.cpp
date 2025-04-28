#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=1e5+5;

int sz[mx];
int pai[mx];
int maior=0;

int find(int u){
    if(pai[u]==u) return u;
    return find(pai[u]);
}

bool unite(int a,int b){
    a=find(a);
    b=find(b);

    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);

        sz[a]+=sz[b];
        pai[b]=a;
        maior=max(sz[a],maior);

        return true;
    }

    return false;
}

void solve() {
    int n,m;cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        sz[i]=1;
        pai[i]=i;
    }
    
    int c=n;
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        if(unite(a,b)) c--;
        cout << c << " " << maior << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

