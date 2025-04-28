#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e5+5;
vector<int> adjc[mx];
vector<int> adjq[mx];
int paic[mx];
int paiq[mx];
int tc = 0;
int tq = 0;
vector<int> distc(mx,-1);
vector<int> distq(mx,-1);

int bfs1(int s, int n, int a){
    //vector<int> dist(n+1,-1);
    distc[s] = 0;
    distq[s] = 0;

    queue<int> q;
    q.emplace(s);
    int maior = 0;
    int i = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(a){
            for(auto v:adjc[u]){
                if(distc[v] == -1){
                    distc[v] = distc[u] + 1;
                    if(distc[v] >= maior){
                        maior = distc[v];
                        i = v;
                    }
                    q.emplace(v);
                }
            }
        }else{
            for(auto v:adjq[u]){
                if(distq[v] == -1){
                    distq[v] = distq[u] + 1;
                    if(distq[v] >= maior){
                        maior = distq[v];
                        i = v;
                    }
                    q.emplace(v);
                }
            }
        }
    }

    return i;
}

int bfs2(int s, int n, int a){
    vector<int> dist1(n+1,-1);
    dist1[s] = 0;
    if(a) paic[s] = -1;
    else paiq[s] = -1;
    
    queue<int> q;
    q.emplace(s);
    int maior = 0;
    int i = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        
        if(a){
            for(auto v:adjc[u]){
                if(dist1[v] == -1){
                    dist1[v] = dist1[u] + 1;
                    if(dist1[v] > maior){
                        maior = dist1[v];
                        i = v;
                    }
                    paic[v] = u;
                    q.emplace(v);
                }
            }
        }else{
            for(auto v:adjq[u]){
                if(dist1[v] == -1){
                    dist1[v] = dist1[u] + 1;
                    if(dist1[v] > maior){
                        maior = dist1[v];
                        i = v;
                    }
                    paiq[v] = u;
                    q.emplace(v);
                }
            }
        }
    }

    return i;
}

vector<int> caminho(int u, int a){
    vector<int> c;

    if(a){
        while(paic[u] != -1){
            c.push_back(u);
            u = paic[u];
        }
        c.push_back(u);
        tc = c.size();
    }else{
        while(paiq[u] != -1){
            c.push_back(u);
            u = paiq[u];
        }
        c.push_back(u);
        tq = c.size();
    }

    return c;
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i=0;i<n-1;i++){
        int a, b;cin >> a >> b;
        adjc[a].push_back(b);
        adjc[b].push_back(a);
    }

    for(int i=0;i<m-1;i++){
        int x, y;cin >> x >> y;
        adjq[x].push_back(y);
        adjq[y].push_back(x);
    }

    int inic = bfs1(1, n, 1);
    int iniq = bfs1(1, m, 0);

    int fimc = bfs2(inic, n, 1);
    int fimq = bfs2(iniq, m, 0);
    
    vector<int> cc = caminho(fimc, 1);
    vector<int> cd = caminho(fimq, 0);
    
    if(tc & 1) tc = tc/2+1;
    else{
        if(distc[cc[tc/2]] > distc[cc[tc/2+1]]) tc = tc/2;
        else tc = tc/2+1;
    }

    if(tq & 1) tq = tq/2+1;
    else{
        if(distq[cd[tq/2]] > distq[cd[tq/2+1]]) tq = tq/2;
        else tq = tq/2+1;
    }
    
    cout << cc[tc-1] << ' ' << cd[tq-1] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
