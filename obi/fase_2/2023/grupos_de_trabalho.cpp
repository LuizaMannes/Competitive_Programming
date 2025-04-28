#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int e,m,d;cin >> e >> m >> d;
    vector<pair<int,int>> quer(m);
    vector<pair<int,int>> nquer(d);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        pair<int,int> ab={a,b};
        quer[i]=ab;
    }

    for(int i=0;i<d;i++){
        int a,b;cin >> a >> b;
        pair<int,int> ab={a,b};
        nquer[i]=ab;
        
    }
    int res=m;
    vector<int> times(e+1);
    for(int i=0;i<e/3;i++){
        int a,b,c;cin >> a >> b >> c;
        times[a]=i;
        times[b]=i;
        times[c]=i;
    }
    for(auto[a,b]:quer){
        if(times[a]==times[b])res--;
    }
    for(auto[a,b]:nquer){
        if(times[a]==times[b])res++;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

