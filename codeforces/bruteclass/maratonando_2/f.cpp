#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int c = 1;
        for ( int i=0; i < n; i++) cin >> arr[i];
        for (int i=0;i < n; i++){
            if(c==arr[i]) c+=2;
            else c++;
        }
        cout << c-1 << endl;
    }
}
