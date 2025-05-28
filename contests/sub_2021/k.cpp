#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
	int t, d, m; cin >> t >> d >> m;
 
	int res = 0, last = 0;
	for(int i = 0; i < m; i++){
		int a; cin >> a;
		if(a - last >= t){
			res = 1;
		}
		last = a;
	}
	if(d - last >= t) res = 1;
	if(m == 0){
		res = (d >= t);
	}
 
	cout << (res ? "Y" : "N") << endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}

