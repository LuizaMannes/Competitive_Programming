#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

vector<string> gray_code(int n){
    if(n == 1) return vector<string> {"0", "1"};

    vector<string> ar, rar;
    ar = rar = gray_code(n - 1);

    reverse(ar.begin(), ar.end());

    for(int i = 0; i < ar.size(); i++){
        ar[i].push_back('0');
        rar[i].push_back('1');
    }

    reverse(ar.begin(), ar.end());
    reverse(rar.begin(), rar.end());
    for(int i = 0; i < rar.size(); i++) ar.push_back(rar[i]);

    return ar;
}

void solve() {
    int n; cin >> n;

    vector<string> res = gray_code(n);

    for(auto s: res) cout << s << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

