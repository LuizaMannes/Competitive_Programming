#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;
const int INF=1e18;

int n;
vector<tuple<int, int, int>> edges;
vector<int> pai(mx);
vector<int> ciclo;
vector<int> dist(mx);
int x=-1;

void bellman_ford() {
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                pai[v]=u;
                x=v;
            }
        }
    }
}

void solve() {
    int m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        edges.emplace_back(a,b,c);
    }
    bellman_ford();
    if(x!=-1){
        for(int i=0;i<n;i++) x=pai[x];
        
        if(x<=0){
            cout << "NO" << endl;
            return;
        }

        for(int i=x;;i=pai[i]){
            ciclo.push_back(i);
            if(i==x && ciclo.size()>1) break;
        }
        reverse(ciclo.begin(),ciclo.end());
     
        cout << "YES" << endl;
        for(auto c:ciclo) cout << c << " ";
        cout << endl;
    }else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

