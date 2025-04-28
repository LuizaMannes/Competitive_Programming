#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    map<int,int> freq;
    map<int,int> index;
    int res=0;
    int cont=0;
    int ini=0;
    for(int i=0;i<n;i++){
        int a;cin >> a;
        if(!freq[a]) cont++;
        else{
            res=max(res,cont);
            if(index[a]>=ini){
                cont-=index[a]-ini;
                ini=index[a]+1;
                //for(int j=0;j<ini;j++) freq[j]=0;
            }else cont ++;
            freq[a]=0;
        }
        index[a]=i;
        freq[a]++;
        //cout << "a : " << a << endl;
       // cout << "cont: " << cont << endl;
       // cout << "freq: " << freq[a] << endl;
       // cout << "index: " << index[a] << endl;
    }
    res=max(res,cont);
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

