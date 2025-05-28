#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=2*1e5;

vector<pair<int,int>> adj[nmax];

bool check(int s, int mid, int aux, int k) {
    vector<int> dist(nmax, -1);
    queue<int> q;
    dist[s] = 0;
    q.emplace(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v,x] : adj[u]) {
            if (dist[v] == -1 && x<= mid) {
                dist[v] = dist[u] + 1;
                q.emplace(v);
                aux++;
            }
        }
    }
    return aux>=k;
}

void solve() {
    int n,m,k; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v,x; cin >> u >> v >> x;
        adj[u].emplace_back(v,x);
        adj[v].emplace_back(u,x);
    }
    int l=0;
    int r=9000;
    int ans=0;
   while(l<=r){
        int mid=(l+r) >> 1;
        int aux=1;
        //cout << mid << " " << aux << endl;
        if(check(1,mid,aux,k)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout << ans << endl;


}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

