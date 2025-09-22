#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;

vector<int> ind(mx), ar(mx);

int check(int a, int b){
    int res = 0;
    if(a < ind[ar[a] - 1]){
        if(b > ind[ar[a] - 1]) res--;
    }else if(a > ind[ar[a] - 1]){
        if(b < ind[ar[a] - 1]) res++;
    }

    if(a < ind[ar[a] + 1]){
        if(b > ind[ar[a] + 1]) res++;
    }else if(a > ind[ar[a] + 1]){
        if(b < ind[ar[a] + 1]) res--;
    }

    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        ind[ar[i]] = i;
    }

    int res = 1;
    for(int i = 2; i <= n; i++) if(ind[i - 1] > ind[i]) res++;
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(ar[a] > ar[b]) swap(a, b);

        if(ar[a] == ar[b] - 1){
            if(a < b){
                if(b >= ind[ar[a] + 1]) res++;
            }else if(a > ind[ar[a] + 1]){
                if(b <= ind[ar[a] + 1]) res--;
            }
        }

        res += check(a, b);
        res += check(b, a);

        swap(ind[ar[a]], ind[ar[b]]);
        swap(ar[a], ar[b]);
        cout << res << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

