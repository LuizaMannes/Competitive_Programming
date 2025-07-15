#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
const int L = 30;

int up[mx][L];
int n;

void bl(){
    for(int i = 1; i < L; i++){
        for(int j = 1; j <= n; j++){
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
}

int kth(int a, int k){
    for(int i = 0; i < L; i++){
        if(k & (1 << i)) a = up[a][i];
    }

    return a;
} 

void solve() {
    int q; cin >> n >> q;
    
    vector<int> next(n + 1);
    vector<vector<int>> before(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> next[i];
        before[next[i]].push_back(i);
        up[i][0] = next[i];
    }

    bl();
    
    vector<int> id_ciclo(n + 1, -2), tam_ciclos;
    map<int,int> pos_ciclo;
    int ciclos = 0;

    for(int i = 1; i <= n; i++){
        if(id_ciclo[i] != -2) continue;
        vector<int> p{i};
        int curr = i;

        while(id_ciclo[next[curr]] == -2){
            id_ciclo[curr] = -1;
            curr = next[curr];
            p.push_back(curr);
        }

        bool ciclo = 0;
        int tam_ciclo = 0;
        for(int u : p){
            if(u == next[curr]) ciclo = 1;
            if(ciclo){
                tam_ciclo++;
                pos_ciclo[u] = tam_ciclo;
            }
            id_ciclo[u] = ciclo ? ciclos : -1;
        }

        if(ciclo){
            tam_ciclos.push_back(tam_ciclo);
            ciclos++;
        }
    }

    vector<int> dist_ciclo(n + 1);
    for(int i = 1; i <= n; i++){
        if(id_ciclo[i] == -1) continue;
        queue<int> q;
        q.emplace(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: before[u]){
                if(id_ciclo[v] != -1) continue;
                dist_ciclo[v] = dist_ciclo[u] + 1;
                q.emplace(v);
            }
        }
    }

    while(q--){
        int a, b;cin >> a >> b;

        if(id_ciclo[a] != -1 && id_ciclo[b] == -1){
            cout << -1 << endl;
            continue;
        }

        if(id_ciclo[a] == -1 && id_ciclo[b] == -1){
            if(dist_ciclo[a] < dist_ciclo[b]) {
                cout << -1 << endl;
                continue;
            }

            int dist = dist_ciclo[a] - dist_ciclo[b]; 
            cout << (kth(a, dist) == b ? dist : -1) << endl;
            continue;
        }

        if(id_ciclo[a] != -1 && id_ciclo[b] != -1){
            if(id_ciclo[a] != id_ciclo[b]){
                cout << -1 << endl;
                continue;
            }

            int u = pos_ciclo[a], v = pos_ciclo[b];
            if(u <= v) cout << v - u << endl;
            else cout << tam_ciclos[id_ciclo[a]] - (u - v) << endl;
            continue;
        }

       if(id_ciclo[a] == -1 && id_ciclo[b] != -1){
            int dist = dist_ciclo[a];
            int root = kth(a, dist);

            if(id_ciclo[root] != id_ciclo[b]){
                cout << -1 << endl;
                continue;
            }

            int u = pos_ciclo[root], v = pos_ciclo[b];
            if(u <= v) cout << dist + (v - u) << endl;
            else cout << dist + (tam_ciclos[id_ciclo[root]] - (u - v)) << endl;
            continue;
       }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

