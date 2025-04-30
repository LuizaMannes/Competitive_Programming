#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> qc(n);
        vector<int> qd(n);
        set<int> set;
        int ans=0;
        for(int i=0;i<n;i++){
            set.emplace(s[i]);
            qc[i] = set.size();
        }
        set.clear();
        for(int i=n-1;i >= 0;i--){
            set.emplace(s[i]);
            qd[i] = set.size();
        }
        for(int i= 0; i<=n-2;i++){
            ans=max(ans,qc[i]+qd[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}
