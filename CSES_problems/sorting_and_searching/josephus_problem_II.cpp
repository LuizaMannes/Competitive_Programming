#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    ordered_set<int> os;
    for(int i = 1; i <= n; i++) os.insert(i);

    int s = k + 1;
    while(os.size() > 1){
        s %= os.size();
        if(s == 0) s = os.size();

        auto it = os.find_by_order(s - 1);
        cout << *it << " ";
        os.erase(it);

        s += k;
    }

    cout << *os.begin() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}


