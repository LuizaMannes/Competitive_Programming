#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

string aumentar(string &atual){
    for(int i=atual.size()-1;i>=0;i--){
        if(atual[i] != '9'){
            atual[i]++;
        //    cout << "c " << atual << endl;
            return atual;
        }else{
            if(i == 0){
                atual[i] = '1';
                atual.push_back('0');
          //      cout << "a " << atual << endl;
                return atual;
            }
            atual[i] = '0';
           // cout << "b " << atual << endl;
        }
    }
    //cout << "d "<< atual << endl;
    return atual;
}

void solve() {
    int n;cin >> n;

    vector<char> ar(n);

    for(int i=0;i<n;i++) cin >> ar[i];

    string res;

    for(int i=0;i<n;i++){
        res+=ar[i];
        string atual = res;
        string comp;
        bool ok = true;
        for(int j=0;j<n;j++){
            if(comp.size() < atual.size()){
                comp+=ar[j];
                continue;
            }else{
                if(comp != atual){
                    ok = false;
                    break;
                }else{
      //              cout << "i: "<< i << ' ' <<  atual << endl;
                    atual = aumentar(atual);
                   
        //                cout << atual << endl;
          //               cout << comp << endl;
                    
                    comp = "";
                    comp+=ar[j];
            //        cout << comp << endl;
                }
            }
        }
        if(i >= n/2 + (n % 2 == 0)) continue;
        if(comp != atual) ok = false;
        if(ok){
            cout << res << endl;
            return;
        }
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

