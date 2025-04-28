#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 5e4+5;

vector<int> adj[mx];
vector<int> dist(mx);
int pai[mx];

void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v!=p){
            dist[v] = dist[u] + 1;
            pai[v] = u;
            dfs(v, u);
        }
    }
}

int cont(int u, int d, int p){
    if(d == 0) return 1;

    int r = 0;
    for(auto v: adj[u]){
        if(v != p) r += cont(v, d-1, u);
    }

    return r;
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[1] = 1;
    dfs(1, 0);

    int ini = 0, maior = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] >= maior){
            maior = dist[i];
            ini = i;
        }
    }

    pai[ini] = -1;
    dist[ini] = 1; 
    dfs(ini, 0);
    
    maior = 0;
    int fim = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] >= maior){
            maior = dist[i];
            fim = i;
        }
    }

    int res = 0;
    if(maior & 1){
        int centro = 0;

        vector<int> path;
        for(int u = fim; pai[u] != -1; u = pai[u]){
            path.push_back(u);
        }

        centro = path[maior/2];

        int soma = 0;
        for(auto u: adj[centro]){
            int r = cont(u, maior/2-1, centro);
            res -= (r * r - r) / 2;
            soma += r;
        }

        res += (soma * soma - soma) / 2;
        cout << maior << endl;
        cout << res << endl;
    }
    
    else{
        int centro1 = 0;
        int centro2 = 0;

        vector<int> path;
        for(int u = fim; pai[u] != -1; u = pai[u]){
            path.push_back(u);
        }

        centro1 = path[maior/2 - 1];
        centro2 = path[maior/2];

        int a = cont(centro1, maior/2 - 1, centro2);
        int b = cont(centro2, maior/2 - 1, centro1);

        cout << maior << endl;
        cout << a * b << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

