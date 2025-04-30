#include <bits/stdc++.h>
using namespace std;
 
int main (){
    int t,a,p,q;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int resposta_posicao = -1;
        int resposta_segundo_valor = -1;
        cin >> a;
        for (int i = 0; i < a; i++) {
            cin >> p >> q;
            if (p <= 10 && q > resposta_segundo_valor) {
                resposta_posicao = i + 1;
                resposta_segundo_valor = q;
            }
        }
        cout << resposta_posicao << endl;
    }
    return 0;
}
