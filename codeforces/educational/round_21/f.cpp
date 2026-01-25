#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const ll INF = 1e18;

struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) { }
};

struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, s, t, m = 0;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1) continue;
                int v = edges[id].v;
                if (level[v] != -1) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != -1;
    }
    ll dfs(int u, ll f) {
        if (f == 0) return 0;
        if (u == t) return f;
        for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(v, min(f, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    ll flow() {
        ll maxflow = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll f = dfs(s, INF)) maxflow += f;
        }
        return maxflow;
    }
};

const int P = 5e6 + 1;
vector<bool> is_prime(P, true);
int lpf[P], primes[P], cnt = 0;
void build() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < P; i++) {
        if (is_prime[i]) {
            lpf[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] < P; j++) {
            is_prime[i * primes[j]] = 0;
            lpf[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;

    build();
    vector<tuple<int,int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        ar[i] = {a, b, c};
    }

    int l = 0, r = 105, res = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;

        Dinic di(n + 2, 0, n + 1);
        int mx1 = 0, id = 0, s = 0;
        for(int i = 0; i < n; i++){
            auto [a, b, c] = ar[i];
            if(c > mid) continue;
            if(b == 1 && mx1 < a){
                mx1 = a;
                id = i;
            }
            if(b & 1) di.add_edge(0, i + 1, a);
            else di.add_edge(i + 1, n + 1, a);
        }

        for(int i = 0; i < n; i++){
            auto [a, b, c] = ar[i];
            if(c > mid) continue;
            if(b == 1 && id != i) continue;
            s += a;
            for(int j = 0; j < i; j++){
                auto [d, e, f] = ar[j];
                if(f > mid) continue;
                if(e == 1 && id != j) continue;
                if(is_prime[e + b]){
                    if(b & 1) di.add_edge(i + 1, j + 1, INF);
                    else di.add_edge(j + 1, i + 1, INF);
                }
            }
        }

        if(s - di.flow() >= k){
            res = mid;
            r = mid - 1;
        }else l = mid + 1;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

