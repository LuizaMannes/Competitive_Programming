#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,x;cin >> n >> x;
    vector<pair<int,int>> eric(n);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        eric[i].first=a;
    }
    for(int i=0;i<n;i++){
        int b; cin >> b;
        eric[i].second=b;
    }
    sort(eric.begin(),eric.end());
    bool pode=true;
    int res=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=eric[i].first;
        if(pode && sum<=x){
            res++;
            if(eric[i].second==1){
                pode = false;
            }
        }else if(!pode && sum<=x){
            if(eric[i].second==0){
                res++;
            }else sum-=eric[i].first;
        }
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

