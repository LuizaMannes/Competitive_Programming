#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s;cin >> s;
    vector<int> freq(2);
    int n=s.size();

    for(int i=0;i<n;i++) freq[s[i]-'0']++;
    
    int res=0;
    for(int i=0;i<n;i++){
        if(freq[1-(s[i]-'0')] == 0){
            res=n-i;
            break;
        }
        freq[1-(s[i]-'0')]--;
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

