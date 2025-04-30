#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> freq(26);
    vector<int> FREQ(26);
    int res=0;

    for(int i=0;i<n;i++){
        int pos=s[i]-'a';
        int POS=s[i]-'A';
        if(pos >= 0){
            freq[pos]++;
        } else{
            FREQ[POS]++;
        }
    }
    for(int i=0;i<26;i++){
        if(freq[i]>0 && FREQ[i]>0){
            res+=min(freq[i],FREQ[i]);
            int m=min(freq[i],FREQ[i]);
            freq[i]=freq[i]-m;
            FREQ[i]=FREQ[i]-m;
        }
    }
 
    for(int i=0;i<26;i++){
        if(k>0 && freq[i]>1){
            int aux=freq[i]/2;
            if(aux<=k){
                res+=aux;
                k-=aux;
            } else{
                res+=k;
                k=0;
            }
        }
        if(k>0 && FREQ[i]>1){
            int aux=FREQ[i]/2;
            if(aux<=k){
                res+=aux;
                k-=aux;
            }else{
                res+=k;
                k=0;
            }
        }
    }


    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc;
    while(tc--){
        solve();
    }
}
