#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        int l=0;
        int r=n - 1;
        while (l < r){
            if (s[l]!=s[r]){
                l++;
                r--;
            } else break;
 
        } 
        cout << r-l+1 << endl;
    }
    return 0;
}
