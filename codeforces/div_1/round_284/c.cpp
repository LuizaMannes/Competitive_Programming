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

void solve() {
    int n, m; cin >> n >> m;

    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    vector<vector<int>> p(n);
    vector<int> t(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        t[i] = sum;
        int x = ar[i];
        for(int j = 2; j * j <= x; j++){
            while(x % j == 0){
                p[i].push_back(j);
                x /= j;
            }
        }
        if(x > 1){
            p[i].push_back(x);
        }

        sum += p[i].size();
    }

    Dinic d(sum + 2, sum, sum + 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p[i].size(); j++){
            if(i & 1){
                d.add_edge(t[i] + j, sum + 1, 1);
            }else{
                d.add_edge(sum, t[i] + j, 1);
            }
        }
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        if(u & 1) swap(u,v);

        for(int j = 0; j < p[u].size(); j++){
            for(int k = 0; k < p[v].size(); k++){
                if(p[u][j] == p[v][k]){
                    d.add_edge(t[u] + j, t[v] + k, 1);
                }
            }
        }
    }

    cout << d.flow() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

