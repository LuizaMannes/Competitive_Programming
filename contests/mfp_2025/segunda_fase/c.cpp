#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    map<vector<int>, int> freq;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];

        vector<int> have(m);
        int l = 0, r = m - 1;
        while(l <= r){
            int aux = (((s[i][l] - 'a') - (s[i][r] - 'a')) % 26) + 26;
            aux %= 26;
            have[l] = have[r] = aux;
            l++; r--;
        }
        freq[have]++;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        vector<int> need(m);
        int l = 0, r = m - 1;
        bool p = 1;
        while(l <= r){
            if(s[i][l] != s[i][r]) p = 0;
            int aux = ((-((s[i][l] - 'a') - (s[i][r] - 'a'))) % 26) + 26;
            aux %= 26;
            need[l] = need[r] = aux;
            l++; r--;
        }
        res += freq[need];
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

