#include <bits/stdc++.h>
using namespace std;
 
int main (){
    int a, b, c, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        if (a + b >= 10) {
            cout << "YES" << '\n'; 
        }
        else if (c + a >= 10) {
            cout << "YES" << '\n'; 
        }
        else if (b+c >=10) {
            cout << "YES" << '\n'; 
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
