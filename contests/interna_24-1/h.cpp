#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=3 * 1e5+10;
const int INF = 1e9;
vector<pair<int, int>> adj[nmax];

bool check(int s, int mid, int n, int k) {
    vector<int> dist(nmax, INF);
    deque<int> q;
    dist[s] = 0;
    q.emplace_back(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto [v,w] : adj[u]) {
            if(w<=mid) w=0;
            else w=1;
            if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                if (w==0) {
                    q.push_front(v);
                } else {
                    q.push_back(v);
                }
            }
        }
    }
    return dist[n]<=k;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v,h; cin >> u >> v >> h;
        adj[u].emplace_back(v,h);
        adj[v].emplace_back(u,h);
    }

    int l=0;
    int r=1e9+10;
    int res=0;

    while(l<=r){
        int mid=(l+r) >> 1;
        if(check(1,mid,n,k)){
            r=mid-1;
            res=mid;
        }else{
            l=mid+1;
        }
    }

    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

