#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin  >> n;

    vector<int> ar(n);
    for(int i=0;i<n;i++) cin >> ar[i];

    int i=0;
    int j=n-1;
    int res=0;
    while(i<j){
        if(ar[i]==ar[j]){
            i++;
            j--;
        }else{
            if(ar[i]<ar[j]){
                i++;
                ar[i]+=ar[i-1];
                res++;
            }else{
                j--;
                ar[j]+=ar[j+1];
                res++;
            }
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

