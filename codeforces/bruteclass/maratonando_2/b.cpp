#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int par = 0;
        int impar = 0;
        int n;
        cin >> n;
        int ar[n];
        for (int j = 0; j < n; j++){
            cin >> ar[j];
            if (ar[j] % 2 == 0){
                par += ar[j];
            }
            else impar += ar[j];
        }
        if (par > impar) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
