#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

using t = tuple<int,int,int>;

void solve() {
    int n; cin >> n;
    
    vector<t> line;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        line.push_back({a, b, i}); 
        line.push_back({b, -a, i}); 
    }

    sort(line.begin(),line.end());

    vector<int> con(n), econ(n);
    set<t> fila;
    queue<t> fin;
    for(auto [a, b, c] : line){
        if(b < 0){
            fila.erase({-b, a, c});
            if(!fila.empty()){
                auto [d, e, f] = *fila.begin();
                if(d <= -b){
                    econ[c] = 1;
                }
            }

            fin.push({-b, a, c});
            while(fin.size() && get<0>(fin.front()) < -b){
                fin.pop();
            }
            if(fin.size() > 1) con[c] = 1;
            continue;
        }

        fila.insert({a, b, c});
    }
    
    for(int i = 0; i < n; i++) cout << con[i] << " ";
    cout << endl;

    for(int i = 0; i < n; i++) cout << econ[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

