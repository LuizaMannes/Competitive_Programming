#include <bits/stdc++.h>
using namespace std;

int main (){
    int num,den,n;
    num = 0;
    den = 0;
    cin >> n;
    for (int i =1; i <= n; i++) {
        int nota, p;
        cin >> nota >> p;
        int aux = nota*p;
        num+= aux;
        den+=p;
    }
    cout << num/den << endl;

    return 0;
}
