#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,m,x; cin >> n >> m >> x;
    vector<set<int>> seta(m+1);
    int mod = n;
    x--;
    int jogada_atual = 0;
    seta[0].emplace(x);
    for(int i=0;i<m;i++){ 
        int r; cin >> r;
        char c; cin >> c;
        for(auto coroas:seta[jogada_atual]){
            if(c=='0'){
               seta[jogada_atual+1].emplace((coroas+r)%mod);
            }
            if(c=='1'){
               seta[jogada_atual+1].emplace(((coroas-r)+mod)%mod);
            }
            if(c=='?'){
                seta[jogada_atual+1].emplace(((coroas-r)+mod)%mod);
                seta[jogada_atual+1].emplace((coroas+r)%mod);
            }
        }
        jogada_atual++; 
    }
    cout << seta[m].size() << endl;
    for(auto coroas:seta[m]) cout << coroas+1 << ' ';
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        solve();
    }
}

