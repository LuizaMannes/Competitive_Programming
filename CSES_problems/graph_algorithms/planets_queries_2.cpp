#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2e5+5;
const int L=30;

vector<int> adj[mx];
int up[mx][L];
int n;

void bl(){
    for(int i = 1; i < L; i++){
        for(int j = 1; j < = n; j++){
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
    for(int i = 1; i <= n; i++){
        cin >> next[i];
        up[i][0] = a;
        adj[i].push_back(a);
    }
    

    while(q--){
        int a,b;cin >> a >> b;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

