#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> freq(26), res(n + 1), m(1 << 26);
    int x = 0, cont = 0;
    for(int i = 1; i <= n; i++){
        int a = s[i - 1] - 'a';
        freq[a]++;
        
        if(freq[a] & 1){
            x ^= (1 << a);
            cont++;
        }
        else{
            x ^= (1 << a);
            cont--;
        }
        
        if(!m[x]) m[x] = i;

        if((cont == 1 && (i & 1)) || (cont == 0 && (i % 2 == 0))){
            res[i] = i;
            continue;
        }

        for(int j = 1; j < (1 << 26); j <<= 1){
            if(x & j){
                if(m[j ^ x] && ((i - m[j ^ x]) & 1)) res[i] = max(res[i], i - m[j ^ x]);
            }else{
                if(m[j | x] && ((i - m[j | x]) & 1)) res[i] = max(res[i], i - m[j | x]);
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res[n] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
