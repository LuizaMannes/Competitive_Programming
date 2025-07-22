#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e6 + 5;
const int mod = 1e9 + 7;
vector<vector<int>> trie(mx, vector<int>(26));
vector<int> dp(5005);

struct tr{
    int end[mx];
    int n_nodos = 0;

    void insert(string &s){
        int id = 0;
        for(char c: s){
            if(!trie[id][c - 'a']) trie[id][c - 'a'] = ++n_nodos;
            id = trie[id][c - 'a'];
        }
        end[id] = 1;
    }   

    int get_values(string &s, int start){
        int id = 0, res = 0;
        for(int i = start; i < s.size(); i++){
            int c = s[i] - 'a';
            if(!trie[id][c]) return res;
            id = trie[id][c];

            if(end[id]){
                res = (res + dp[i + 1]) % mod;
            }
        }
        return res;
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();

    tr t;
    int k; cin >> k;
    
    for(int i = 0; i < k; i++){
        string r; cin >> r;
        t.insert(r);
    }

    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = t.get_values(s, i);
    }

    cout << dp[0] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

