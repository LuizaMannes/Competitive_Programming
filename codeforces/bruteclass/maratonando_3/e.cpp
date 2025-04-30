#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int tc;cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n);
        vector<int> er(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        for(int i=0;i<n;i++) {
            er[i]=arr[i];
        }
        sort(arr.begin(),arr.end());
        bool flag = true;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=er[i]%2)
            flag = false;
        }
 
        if(flag) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
 
    }
 
 
}
