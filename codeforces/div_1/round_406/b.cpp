#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5 + 5;
vector<pair<int, int>> adj[4 * mx];

void build(int p, int l, int r){
    if(l != r){
        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        adj[p].push_back({p * 2, 0});
        adj[p].push_back({p * 2 + 1, 0});
    }
}

int find1(int p, int l, int r, int u){
    if(l == r) return p;
    else{
        int mid = (l + r) / 2;
        if(mid >= u) return find1(p * 2, l, mid, u);
        else return find1(p * 2 + 1, mid + 1, r, u);
    }
}

void find2(int p, int l, int r, int L, int R, int u, int c){
    if(l > R || r < L) return;
    if(l >= L && r <= R) {
        adj[u].push_back({p, c});
    }else{
        int mid = (l + r) / 2;
        find2(p * 2, l, mid, L, R, u, c);
        find2(p * 2 + 1, mid + 1, r, L, R, u, c);
    }
}

void find3(int p, int l, int r, int L, int R, int u, int c){
    if(l > R || r < L) return;
    if(l >= L && r <= R) {
        adj[p].push_back({u, c});
    }else{
        int mid = (l + r) / 2;
        find3(p * 2, l, mid, L, R, u, c);
        find3(p * 2 + 1, mid + 1, r, L, R, u, c);
    }
}

void solve() {
    int n, q, s; cin >> n >> q >> s;
    n--;
    s--;

    build(1, 0, n);

    for(int i = 0; i < q; i++){
        int t; cin >> t;

        if(t == 1){
            int u, v, c; cin >> u >> v >> c;
            u--, v--;
            u = find1(1, 0, n, u), v = find1(1, 0, n, v);
            adj[u].push_back({u, c}); 
        }

        if(t == 2){
            int u, l, r, c; cin >> u >> l >> r >> c;
            u--, l--, r--;
            u = find1(1, 0, n, u);
            find2(1, 0, n, l, r, u, c);
        }
        
        if(t == 3){
            int u, l, r, c; cin >> u >> l >> r >> c;
            u--, l--, r--;
            u = find1(1, 0, n, u);
            find3(1, 0, n, l, r, u, c);
        }
    }

    for(int i = 0; i <= n; i++){
        cout << "i " << i << endl;
        for(auto [v, c]: adj[i]){
            cout << v << " " << c << endl;
        }
    }


    vector<int> dist(4 * n, 1e9 + 9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    s = find1(1, 0, n, s); 
    while(s){
        dist[s] = 0;
        pq.emplace(0, s);
        s /= 2;
    }

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(dist[u] != w) continue;

        for(auto [v, c]: adj[u]){
            if(w + c < dist[v]){
                dist[v] = w + c;
                pq.emplace(dist[v], v);
            }
        }
    }

    for(int i = 0; i <= n; i++){
        int a = find1(1, 0, n, i);
        cout << (dist[a] == 1e9 + 9? -1 : dist[a]) << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

