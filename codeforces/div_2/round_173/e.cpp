#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int bits = 41;
const int mx = 1e5 + 5;

vector<vector<int>> go(mx * bits, vector<int>(2, -1));
int root = 0, cnt = 1;

void insert(int x){
    int v = root;
    for(int i = bits - 1; i >= 0; i--){
        int b = x >> i & 1;

        if(go[v][b] == -1) go[v][b] = cnt++;
        v = go[v][b];
    }
}

int max_xor(int x){
    int v = root;
    int ans = 0;

    if(cnt <= 1) return -1;

    for(int i = bits - 1; i >= 0; i--){
        int b = x >> i & 1;
        int good = go[v][!b];
        int bad = go[v][b];

        if(good != -1){
            v = good;
            ans |= 1ll << i;
        }else v = bad;
    }

    return ans;
}
    
void solve() {
    int n; cin >> n;

    vector<int> ar(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ar[i + 1] = ar[i] ^ x;
    }

    int res = 0;

    for(int i = 0; i <= n; i++){
        insert(ar[i]);
        res = max(res, max_xor(ar[i] ^ ar[n]));
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

