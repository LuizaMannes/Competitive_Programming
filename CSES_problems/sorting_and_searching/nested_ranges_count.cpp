#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


using t = tuple<int,int,int>;

const int inf = 1e9 + 1;

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
    ordered_set<pair<int,int>> atual, fin;

    for(auto [a, b, c]: line){
        if(b < 0){
            atual.erase({-b,c});
            econ[c] = atual.order_of_key({-b + 1, 0});

            if(fin.size()){
                con[c] = fin.size() - fin.order_of_key({-b - 1, inf});
            }
            fin.insert({-b, c});
            continue;
        }
        atual.insert({a,c});
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

