#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,d;cin >> n >> d;
    map<int,int> freqm,freqM;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        int aux=0;
        if(a>=d){
            aux=a-d;
            freqM[aux]++;
        }else{
            aux=a+d;
            freqm[aux]++;
        }
    }
    int res=0;
    for(auto [c,d]:freqm){
        res++;
        if(freqM[c]){
            res++;
            freqM[c]=0;
        }
    }
    for(auto [c,d]:freqM){
        if(d==1) res++;
        else if(d>1) res+=2;
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

