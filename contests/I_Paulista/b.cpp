#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

using ll = long long;
using T = pair<ll,int>;

const int mx = 1e5 + 5;
const ll inf = 1e18;

int n;

vector<pair<int,int>> adj[mx];
vector<ll> dist(mx, inf);

bool dij(int s, ll mid){
    vector<ll> distc(n + 1, inf);

    distc[s] = -mid;
    priority_queue<T, vector<T>, greater<>> p;
    p.emplace(distc[s], s);
    while(!p.empty()){
        auto [d, u] = p.top();
        if(u == n) return true;
        p.pop();

        if(d != distc[u]) continue;

        for(auto [v, w] :adj[u]){
            if(distc[v] > d + w && d + w <= dist[v]){
                distc[v] = d + w;
                p.emplace(distc[v], v);
            }
        }
    }

    return false;
}

void solve() {
    int m, k; cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<T, vector<T>, greater<>> pq;
    for(int i = 0; i < k; i++){
        int a; cin >> a;
        dist[a] = 0;
        pq.emplace(0, a);
    }

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d != dist[u]) continue;

        for(auto [v, w] :adj[u]){
            if(dist[v] > d + (w * 2)){
                dist[v] = d + (w * 2);
                pq.emplace(dist[v], v);
            }
        }
    }

    ll l = 0, r = 1e10 + 10, res = 0;
    while(l <= r){
        ll mid = (l + r) / 2;

        if(dij(1, mid)){
            r = mid - 1;
            res = mid;
        }else l = mid + 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

