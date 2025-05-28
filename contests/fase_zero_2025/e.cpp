#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int> div;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            div.push_back(i);
            if(n / i != i) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());

    int atual = 1;
    for(auto i: div){
        if(i == 1) continue;
        if(i % atual == 0){
            int aux = i / atual - 1;
            if(aux > k){
                atual += atual * k;
                k = 0;
            }else{
                k -= aux;
                atual = i;
            }
        }
        if(k == 0) break;
    }

    if(k){
        atual += atual * k;
    }

    cout << atual << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

