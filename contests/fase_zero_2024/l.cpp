#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<string> s, novo;
    map<string,int> freq;
    for(int i=0;i<n;i++){
        string x; cin >> x;
        s.push_back(x);
        freq[x]++;
    }
    for(int i=0;i<n;i++){
        string y; cin >> y;
        novo.push_back(y);
    }
    vector<string> res;
    int j=0;
    for(int i=0;i<n;i++){
        if(freq[novo[j]]==0){
            while(freq[novo[j]]==0) j++;
        }
        freq[s[i]]--;
        if(s[i]==novo[j]) {
            res.push_back(novo[j]);
            j++;
        }else{
            res.push_back(novo[j]);
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << " \n" [i==res.size()-1];
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

