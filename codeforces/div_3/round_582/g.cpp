#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
vector<int> par(mx), sz(mx, 1);

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

void solve() {
    int n, q; cin >> n >> q;

    for(int i = 0; i <= n; i++) par[i] = i;
   
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < n - 1; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end());

    vector<pair<int,int>> queries;
    for(int i = 0; i < q; i++){
        int a; cin >> a;
        queries.push_back({a,i});
    }

    sort(queries.begin(), queries.end());

    vector<int> res(q);
    int j = 0, atual = 0;
    for(int i = 0; i < n - 1; i++){
        auto [c, u, v] = edges[i];
        while(j < q && c > queries[j].first) {
            res[queries[j].second] = atual;
            j++;
        }

        int a = find(u), b = find(v);
        atual -= (sz[a] * (sz[a] - 1) / 2) + (sz[b] * (sz[b] - 1) / 2);
        unite(u, v);
        a = find(u);
        atual += sz[a] * (sz[a] - 1) / 2;
    }

    while(j < q) {
        res[queries[j].second] = atual;
        j++;
    }

    for(int i = 0; i < q; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

