#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5, L = 21;

vector<vector<int>> adj(mx), inv(mx);
vector<int> adjc[mx];
vector<int> topo;
int val[mx], B[L], R = 0, last_bit = 0, comp[mx], vis[mx];

void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    inv[v].emplace_back(u);
}

void toposort(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        toposort(v);
    }
    topo.emplace_back(u);
}

void dfs(int u, int r) {
    vis[u] = 1;
    comp[u] = r;
    for (auto v : inv[u]) {
        if (vis[v]) continue;
        dfs(v, r);
    }
}

int reduce(int x) {
    for (int i = L - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (B[i] != 0) {
                x ^= B[i];
            } else {
                last_bit = i;
                return x;
            }
        }
    }

    return 0;
}

bool insert(int x) {
    x = reduce(x);
    if (x > 0) {
        R++;
        B[last_bit] = x;
        return true;
    }
    return false;
}

vector<int> last;
vector<int> vcomp[mx], csz(mx);
bool deu = false;
void res(int u, int sizep){
    if(deu) return;

    if(sizep > 20){
        cout << "YES" << endl;
        deu = 1;
        return;
    }

    for(int v: vcomp[u]){
        if(!insert(v)){
            cout << "YES" << endl;
            deu = 1;
            return;
        }

        last.push_back(last_bit);
    }


    for(auto v: adjc[u]){
        res(v, sizep + csz[v]);
    }

    for(int i = 0; i < csz[u]; i++){
        if(last.size()){
            B[last.back()] = 0;
            last.pop_back();
        }
    }
}

void solve() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        if(a != 0) add_edge(i, a);
        if(b != 0) add_edge(i, b);
    }

    for(int i = 1; i <= n; i++) cin >> val[i];

    toposort(1);

    fill(vis, vis + n + 1, 0);

    int c = 1;
    reverse(topo.begin(), topo.end());
    for(auto i: topo) if(!vis[i]) dfs(i, c++);

    vector<int> can(n + 1), ok(n + 1);

    auto&& canI = [&](auto&& self, int u, vector<vector<int>>& adj) -> void{
        vis[u] = 1;
        if(can[u]) ok[u] = 1;
        can[u] = 1;
        for(auto v: adj[u]){
            if(!vis[v]) self(self, v, adj);
        }
    };

    fill(vis, vis + n + 1, 0);
    canI(canI, 1, adj);
    fill(vis, vis + n + 1, 0);
    canI(canI, n, inv);

    for(int i = 1; i <= n; i++){
        for(auto v: adj[i]){
           if(ok[i] && ok[v]){
                if(comp[i] != comp[v]) adjc[comp[i]].push_back(comp[v]);
           }
        }
    }

    for(int i = 1; i <= n; i++){
        if(ok[i]){
            vcomp[comp[i]].push_back(val[i]);
            csz[comp[i]]++;
        }
    }

    res(comp[1], csz[1]);
    
    if(!deu) cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

