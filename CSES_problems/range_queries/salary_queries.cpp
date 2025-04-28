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

const int inf = 1e9;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> ar(n);
    ordered_set<pair<int,int>> o;

    for(int i = 0; i < n; i++){
        cin >> ar[i];
        o.insert({ar[i], i});
    }

    while(q--){
        char a; cin >> a;
        if(a == '!'){
            int x, k; cin >> x >> k;
            x--;
            o.erase({ar[x], x});
            ar[x] = k;
            o.insert({ar[x], x});
        }else{
            int b, c; cin >> b >> c;
            cout << o.order_of_key({c, inf}) - o.order_of_key({b, -inf}) << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

