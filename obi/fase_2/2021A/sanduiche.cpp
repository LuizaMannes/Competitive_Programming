#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=25;

int n;

int r[N][N];
int c[N];
int res=0;

void com(int x){
    if(x==n){
        bool z=1;
        for(int i=0;i<n;i++){
            if(c[i]!=0) z=0;
        }
        if(!z) res++;
        return;
    }
    
    com(x+1);
    c[x]=1;
    bool ok = true;
    for(int i=0;i<n;i++){
       if(c[i] && r[i][x]) ok = false;
    }
    
    if(ok){
        com(x+1);
    }
    c[x]=0;
}

void solve() {
    int m; cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        a--; b--;
        r[a][b]=r[b][a]=1;
    }

    com(0);

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

