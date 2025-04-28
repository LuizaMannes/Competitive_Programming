#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    int soma=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        soma+=a[i];
    }

    soma/=n;

    for(int i=0;i<n;i++){
        cout << soma-a[i] << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

