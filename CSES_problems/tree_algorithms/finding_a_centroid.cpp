#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> adj[mx], sz(mx), pai(mx, -1);

int find_size(int u, int p){
    sz[u] = 1;

    for(int v: adj[u]){
        if(v != p){
            sz[u] += find_size(v, u);
        }
    }

    return sz[u];
}

int find_centroid(int u, int p, int s){
    for(auto v: adj[u]){
        if(v != p){
            if(sz[v] > s / 2){
                return find_centroid(v, u, s);
            }
        }
    }

    return u;
}

int init_centroid(int u, int p){
    find_size(u, 0);

    int c = find_centroid(u, 0, sz[u]);
    return c;
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << init_centroid(1, -1) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
