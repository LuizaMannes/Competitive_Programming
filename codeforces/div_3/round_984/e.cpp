#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k, q; cin >> n >> k >> q;

    vector<vector<int>> ar(n, vector<int> (k));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> ar[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < k; j++){
            ar[i][j] |= ar[i-1][j];
        }
    }

    while(q--){
        int m; cin >> m;
        int menor = 0, maior = n - 1;

        while(m--){
            int j; cin >> j;
            char o; cin >> o;
            int c; cin >> c;
            j--;

            if(o == '>'){
                int l = -1, r = n;

                while(l + 1 != r){
                    int mid = (l + r) >> 1;
                    if(ar[mid][j] <= c) l = mid;
                    else r = mid;
                }
                if(r > menor) menor = r;
            } else{
                int l = -1, r = n;

                while(l + 1 != r){
                    int mid = (l + r) >> 1;
                    if(ar[mid][j] < c) l = mid;
                    else r = mid;
                }
                if(l < maior) maior = l; 
            }
        }
        cout << (menor <= maior ? menor + 1 : -1) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

