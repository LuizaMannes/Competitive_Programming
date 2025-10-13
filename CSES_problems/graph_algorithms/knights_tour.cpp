#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int n = 8;
vector<pair<int,int>> mv = {{2, 1}, {1, 2}, {-1, 2}, {-2 ,1}, 
                            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
vector<vector<int>> tab(n, vector<int> (n, -1));

bool pode(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n && tab[x][y] == -1;
} 

int cnt(int x, int y){
    int count = 0;

    for(auto [i, j]: mv){
        int xx = x + i;
        int yy = y + j;
        if(pode(xx, yy)) count++;
    }

    return count;
}

vector<pair<int,int>> getmoves(int x, int y){
    vector<pair<int,int>> moves;

    for(int i = 0; i < n; i++){
        auto [j, k] = mv[i];
        int xx = x + j;
        int yy = y + k;

        if(pode(xx, yy)){
           int opt = cnt(xx, yy);
           moves.push_back({opt, i});
        }
    }

    sort(moves.begin(), moves.end());

    return moves;
}

bool tour(int x, int y, int step){
    if(step == n * n) return true;

    vector<pair<int,int>> moves = getmoves(x, y);

    for(auto [c, i]: moves){
        auto [j, k] = mv[i];
        int xx = x + j;
        int yy = y + k;

        tab[xx][yy] = step + 1;
        if(tour(xx, yy, step + 1)) return true;

        tab[xx][yy] = -1;
    }

    return false;
}

void solve() {
    int x, y; cin >> x >> y;    
    x--; y--;
    swap(x, y);
    tab[x][y] = 1;

    if(tour(x, y, 1)){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cout << tab[i][j] << " ";
            }
            cout << endl;
        }
    } else cout << -1 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

