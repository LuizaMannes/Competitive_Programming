#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct node{
    int a;
    node *l;
    node *r;
};

void solve() {
    int n; cin >> n;
    
    vector<node> ar(n + 1);
    for(int i = 1; i <= n; i++) {
        ar[i].a = i;
        if(i != 1) ar[i].l = &ar[i - 1];
        else ar[i].l = &ar[n];
        if(i != n) ar[i].r = &ar[i + 1];
        else ar[i].r = &ar[1];
    }

    vector<int> res;
    node *atual = (n == 1 ? &ar[1] : &ar[2]);
    while(res.size() != n){
       res.push_back(atual -> a);
       atual -> l -> r = atual -> r;
       atual -> r -> l = atual -> l;
       atual = atual->r->r;
    }

    for(auto i: res) cout << i << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

