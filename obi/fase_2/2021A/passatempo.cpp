#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int l,c;cin >> l >> c;

    vector<vector<string>> ar(l,vector<string> (c));
    vector<int> li(l);
    vector<int> co(c);
    map<string,int> res;

    for(int i=0;i<l;i++){
        for(int j=0;j<c+1;j++){
            if(j!=c && i!=l){
                cin >> ar[i][j]; 
                continue;
            }
            int a;cin >> a;
            li[i] = a;
        }
    }

    for(int i=0;i<c;i++){
        int a;cin >> a;
        co[i] = a;
    }


    for(int i=0;i<max(l,c);i++){
        for(int j=0;j<l;j++){
            string aux;
            int cont=0;
            bool dr=false;
            bool pri=true;
            int p=li[j];
            for(int k=0;k<c;k++){
                if(res[ar[j][k]]) p-=res[ar[j][k]];

                if(!res[ar[j][k]] && ar[j][k]!=aux) {
                    if(!pri){
                        dr=true;
                        break;
                    }
                    aux=ar[j][k];
                    pri=false;
                }
                if(ar[j][k]==aux) cont++;
            }
            if(cont == 0) continue;
            if(!dr) res[aux]=p/cont;
        }

        for(int j=0;j<c;j++){
            string aux;
            int cont=0;
            bool dr=false;
            bool pri=true;
            int p=co[j];
            for(int k=0;k<l;k++){
                if(res[ar[k][j]]) p-=res[ar[k][j]];

                if(!res[ar[k][j]] && ar[k][j]!=aux) {
                    if(!pri){
                        dr=true;
                        break;
                    }
                    aux=ar[k][j];
                    pri=false;
                }
                if(ar[k][j]==aux) cont++;
            }
            if(cont == 0) continue;
            if(!dr) res[aux]=p/cont;
        }
    }

    for(auto [a,b]: res){
        cout << a << " " << b << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

