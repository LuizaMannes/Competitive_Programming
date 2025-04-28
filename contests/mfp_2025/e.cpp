#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn = 105;
vector<vector<int>> ar(maxn, vector<int> (maxn));
int n, m;
vector<pair<int,int>> mv = {{-1, 0}, {0, -1}};

bool pode(int i, int j){
    return i < n && j < m && i >=0 && j >= 0;
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[i][j];
            ar[i][j]++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool igual = 0;
            for(auto [x, y]: mv){
                if(pode(x + i, y + j)){
                    if(ar[x + i][y + j] == ar[i][j]) igual = 1;
                }
            }
            if(igual) ar[i][j]--;
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

