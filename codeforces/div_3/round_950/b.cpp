#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,f,k; cin >> n >> f >> k;
    vector<int> cubo(n);
    map<int,int> freq;
    for(int i=0;i<n;i++){
        cin >> cubo[i];
        freq[cubo[i]]++;
    }
    int fav=cubo[f-1];
    sort(cubo.begin(),cubo.end());
    reverse(cubo.begin(),cubo.end());
    int i=0;
    int a=0;
    for(int i=0;i<n;i++){
        if(cubo[i]==fav){
            a=i;
            break;
        }
    }
    while(k--){
        freq[cubo[i]]--;
        i++;
    }
    i--;
    if(freq[fav]==0) cout << "YES" << endl;
    else if(freq[fav]>=1 && i<a ) cout << "NO" << endl;
    else if(freq[fav]>=1 && i>=a) cout << "MAYBE" << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

