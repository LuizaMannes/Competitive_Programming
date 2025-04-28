#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int nmax=1e5+10;

vector<int> pais(nmax);
vector<int> adj[nmax];
vector<int> vis(nmax);
vector<pair<int,int>> depht(nmax);
priority_queue<pair<int,int>> pq;

void prof(int u){
    vis[u]++;
    for(auto v:adj[u]){
        if(vis[v]==0){
            depht[v].first=depht[pais[v]].first+1;
            prof(v);
        }
    }
}

int dfs(int u,int res,int ult){
    vis[u]++;
    //cout << "u: " << u << " " << "res: " << res << endl;
    for(auto v:adj[u]){
        if(vis[v]==0 && v!=ult){
            //cout << "v: " <<  v << endl;
            if(v!=pais[u]){
                //cout << "depht v: " << depht[v].first << endl;
                //cout << "depht u: " << depht[u].first << endl;
                depht[v].first-=depht[u].first;
                //cout << "depht v-u: " << depht[v].first << endl;
                pq.emplace(depht[v]);
                ult=u;
                vis[v]=-1;
                dfs(v,res,ult);
            }else {
                res++;
                ult=u;
                return dfs(v,res,ult);
            }
        }
    }
    return res;
}

void solve() {
    int n,k;cin >> n >> k;
    pais[1]=0;
    depht[1].first=1;
    depht[1].second=1;
    for(int i=2;i<=n;i++){
        int a;cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
        pais[i]=a;
        depht[i].second=i;
    }
    int res=0;
    prof(1);
    int a=0,b=0;
    for(int i=0;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        if(depht[i].first>a) {
            b=i;
            a=depht[i].first;
        }
    }
    //sort(depht.begin(),depht.end());
    //reverse(depht.begin(),depht.end());
    pq.emplace(depht[b]);
    while(k--){
        auto[u,v]=pq.top();
        pq.pop();
        while(vis[v]!=0 && !pq.empty()){
            auto[u,v]=pq.top();
            pq.pop();
        }
        cout << u << " " << v << endl;
        //if(vis[v]!=0){
        //}
        int aux=1;
        aux=dfs(v,aux,0);
        res+=aux;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

