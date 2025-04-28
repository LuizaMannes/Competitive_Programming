#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx=2*1e5+5;

void solve() {
    int n;cin >> n;
    vector<set<int>> rua(mx);
    int aux=0;
    map<int,int>freq;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        if(freq[a]==0) aux++;
        freq[a]=1;
        rua[a].emplace(b);
    }
    for(int i=0;i<aux;i++){
        int a=rua[i].size();
        int b=0;
        int c=0;
        if(a&1){
            b=a/2+1;
        }else{
            b=a/2;
            c=a/2+1;
        }
        int cont=0;
        for(auto c:rua[i]){
            if(cont<b) continue;

        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
