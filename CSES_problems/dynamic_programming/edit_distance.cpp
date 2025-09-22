#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int m, n;
    m = a.size(); n = b.size();

    int M[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        M[i][0] = i;
    }

    for(int j = 0; j <= n; j++){
        M[0][j] = j;
    }

    int custo = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]) custo = 0;
            else custo = 1;

            M[i][j] = min({M[i - 1][j] + 1, M[i - 1][j - 1] + custo, M[i][j - 1] + 1});
        }
    }

    cout << M[m][n] << endl;
}
