#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int x, y; cin >> x >> y;

    if(x >= 0 && x <= 100 && y >= 0 && y <= 100){
        //cout << "a" << endl;
        if(-y + 100 >= x) cout << "S" << endl;
        else cout << "N" << endl;
        return;
    }

    if(x >= 0 && x <= 100 && y <= 0 && y >= -100){
        //cout << "b" << endl;
        cout << "S" << endl;
        return;
    }

    if(x >= 100 && x <= 200 && y <= 0 && y >= -100){
        //cout << "c" << endl;
        if(y + 200 >= x) cout << "S" << endl;
        else cout << "N" << endl;
        return;
    }

    if(x <= 0 && x >= -100 && y >= 0 && y <= 100){
        //cout << "d" << endl;
        cout << "S" << endl;
        return;
    }

    if(x >= -200 && x <= -100 && y >= 0 && y <= 100){
        //cout << "e" << endl;
        if(y - 200 <= x) cout << "S" << endl;
        else cout << "N" << endl;
        return;
    }

    if(x >= -100 && x <= 0 && y >= -100 && y <= 0){
        //cout << "f" << endl;
        if(-y - 100 <= x) cout << "S" << endl;
        else cout << "N" << endl;
        return;
    }

    cout << "N" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

