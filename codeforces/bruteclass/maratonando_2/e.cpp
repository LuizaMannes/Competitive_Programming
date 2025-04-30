#include <bits/stdc++.h>
using namespace std;
 
int main (){
    int m;
    cin >> m;
    for(int i = 0;i<m;i++){
        char letra;
        cin >> letra;
        if(letra=='c'||letra == 'o'|| letra == 'd'|| letra == 'e'|| letra == 'f'|| letra == 'r'||letra == 's'){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}

