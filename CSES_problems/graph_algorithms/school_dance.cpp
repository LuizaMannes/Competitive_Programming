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

    void res(int mx){
        for(auto e: edges){
            if(e.flow > 0 && e.u != s && e.v != t){
                cout << e.u << " " << (e.v - mx) << endl;
            }
        }
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;

    Dinic d(n + m + 2, 0, n + m + 1);
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        b += n;
        d.add_edge(a, b, 1);
    }

    for(int i = 1; i <= n; i++) d.add_edge(0, i, 1);
    for(int i = n + 1; i <= n + m; i++) d.add_edge(i, n + m + 1, 1);

    cout << d.flow() << endl;
    d.res(n);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

