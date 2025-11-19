#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
typedef long long ll;

const ll INF = 1e18;

vector<pair<int,int>> moves = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}, {-1, 2}};

bool pode(int i, int j, int n){
    return i > 0 && i <= n && j > 0 && j <= n;
}

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

int c(int i, int j, int n){
    return (i - 1) * n + j;
}


void solve() {
    int n, k; cin >> n >> k;

    vector<vector<int>> m(n + 1, vector<int> (n + 1, 0));
    vector<pair<int,int>> kn(k);
    Dinic d(c(n, n, n) + 2, 0, c(n, n, n) + 1);
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        kn[i] = {x,y};
        m[x][y] = 1;
    }

    int cc = 0, last = cc;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cc and m[i][j]){
                d.add_edge(0, c(i,j,n), 1);
                for(auto [ii, jj]: moves){
                    if(pode(i + ii, j + jj, n) and m[i + ii][j + jj] == 1){
                        d.add_edge(c(i,j,n), c(i + ii, j + jj, n), INF);
                    }
                }
            }
            else if(m[i][j]){
                d.add_edge(c(i,j,n), c(n, n, n) + 1, 1);
            }
            cc ^= 1;
        }
        cc = last ^ 1;
        last = cc;
    }
    
    cout << d.flow() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

