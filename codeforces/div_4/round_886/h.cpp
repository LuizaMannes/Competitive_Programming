#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using T=pair<int,int>;

const int mx=2*1e5+10;
const int INF=1e9;

vector<pair<int,int>> adj[mx];
vector<int> dist(mx,INF);

bool dij(int s){
    dist[s]=0;
    priority_queue<T,vector<T>,greater<>> pq;
    pq.emplace(dist[s],s);
    while(!pq.empty()){
        auto[d,n]=pq.top();
        pq.pop();
        if(d!=dist[n]) return false;
        for(auto[w,v]:adj[n]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.emplace(dist[v],v);
            }else if(dist[v]!=d+w) return false;
        }
    }
    return true;
}

void solve() {
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].emplace_back(c,b);
    }
    
    cout << (dij(1)?"YES":"NO") << endl;
    for(int i=0;i<=n;i++){
        dist[i]=INF;
        adj[i].clear();
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

