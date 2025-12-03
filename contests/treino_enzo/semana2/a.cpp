#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

vector<int> par, sz;

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
    int n; cin >> n;

    par.assign(n, 0);
    iota(par.begin(), par.end(), 0);
    sz.assign(n, 1);

    vector<pair<int,int>> ar(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ar[i] = {a,i};
    }

    sort(ar.begin(),ar.end());
    vector<int> vis(n), res(n, -1);
    int cur = 0, can = 0;
    for(int i = 0; i < n; i++){
        auto[v, ind] = ar[i]; 
        vis[ind] = 1;

        if(ind > 0 and vis[ind - 1]){
            can -= (sz[find(ind - 1)] + 1) / 2;
            unite(ind, ind - 1);
        }

        if(ind < n - 1 and vis[ind + 1]){
            can -= (sz[find(ind + 1)] + 1) / 2;
            unite(ind, ind + 1);
        }

        can += (sz[find(ind)] + 1) / 2;
        while(cur < can){
            res[cur] = v;
            cur++;
        }
    }

    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

