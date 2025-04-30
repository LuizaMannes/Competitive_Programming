#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    map<int,int> freq;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++){
        int a;cin >> a;
        freq[a]++;
    }
    for(auto[x,y]:freq){
        int aux=x;
        while(aux<=n){
            pos[aux]+=y;
            aux+=x;
        }
    }
    sort(pos.begin(),pos.end());
    cout << pos[n] << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

