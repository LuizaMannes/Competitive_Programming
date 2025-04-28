#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    vector<string> ar(n);
    map<string,int> freq;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        freq[ar[i]]++;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        set<string> subs;

        for(int j = 0; j < ar[i].size(); j++){
            string s = "";
            for(int k = j; k < ar[i].size(); k++){
                s += ar[i][k];
                subs.emplace(s);
            }
        }

        for(auto a: subs){
            res += freq[a];
        }
    }

    cout << res - n << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

