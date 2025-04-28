#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7;

vector<vector<int>> mult(vector<vector<int>> &a, vector<vector<int>> &b){
    vector<vector<int>> c(2, vector<int> (2));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] += (a[i][k] * b[k][j]) % mod;
            }
        }
    }
    
    return c;
}

vector<vector<int>> binexp(vector<vector<int>> &b, int n){
    vector<vector<int>> r = {{1, 0}, {0, 1}};
    
    while(n){
        if(n & 1) r = mult(r, b);

        b = mult(b, b);
        n >>= 1;
    }

    return r;
}

void solve() {
    int n; cin >> n;
    
    vector<vector<int>> b = {{0 , 1}, { 1, 1}};

    b = binexp(b, n);


    cout << b[0][1] % mod << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

