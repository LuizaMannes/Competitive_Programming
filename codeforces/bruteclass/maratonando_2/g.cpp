#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> freq(26);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int pos = s[i]-'A';
            if(freq[pos] == 0){
                ans+=2;
                freq[pos]++;
            } else ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
