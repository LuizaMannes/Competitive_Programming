#include <bits/stdc++.h>
#define int long long

using namespace std;
//using ll = long long;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);    
    int n, x; cin >> n >> x;

    string s, t; cin >> s >> t;

    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[(i + x) % n]) count ++;
    }

    cout << count << endl;
}