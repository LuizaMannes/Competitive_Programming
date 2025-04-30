#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

vector<string> ar;

bool sorta(int a, int b){
    if(ar[a - 1][b - 1] == '1') return a < b;
    return a > b;
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        ar.push_back(s);
    }

    vector<int> res(n);

    int a = n;
    for(int i = 0; i < n; i++){
        res[i] = a;
        a--;
    }

    sort(res.begin(), res.end(), sorta);

    for(auto b : res){
        cout << b << " ";    
    }

    cout << endl;

    for(int i = 0; i < n; i++) ar.clear();
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

