#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;

    if(n==1){
        cout << 1 << endl;
        return;
    }
    if(n==2){
        cout << -1 << endl;
        return;
    }

    if(n & 1){
        int a=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << a << " ";
                a++;
            }
            cout << endl;
        }
    }else{
        int a=1;
        int ar[n][n];
        double b=1/(double)n;
        double soma2=0;
        for(int i=0;i<n;i++){
            double soma=0;
            for(int j=0;j<n;j++){
                if(j<n-1){
                    soma+=(double)a;
                    if(j==0) soma2+=(double)a;
                    cout << a << ' ';
                    ar[i][j]=a;
                    a++;
                    continue;
                }
                a--;
                soma/=(double)n;
                double c = (double)a;
                c-=soma;
                c/=b;
                ar[i][j]=(int)c;
                cout << c << endl;
                if(i==n-2){
                    int au=(int)soma2;
                    soma2/=(double) n;
                    double d = (double) ar[i][0];
                    d-=soma2;
                    d/=b;
                    a=(int)d;
                    au+=(int)d;
                    if((int)au%n) a++; 
                    //if((int)au%n==0)cout << "ok" << endl;
                    //else cout << au << endl;
                }
                else a=(int)c+1;
            }
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

