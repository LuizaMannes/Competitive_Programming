#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define T pair<int,int>
 
void solve(){
	int n, k; cin >> n >> k;
	vector<vector<int>> a(k);
    vector<int> b;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		y--;
		a[y].emplace_back(x);
        b.emplace_back(y);
	}
 
	for (int i = 0; i < k; i++) {
		sort(a[i].rbegin(), a[i].rend());
	}
 
	vector<int> s;
	for (int i = 0; i < n; i++) {
		s.emplace_back(a[b[i]].back());
		a[b[i]].pop_back();
	}
 
    bool ok = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i - 1]) ok = false;
    }
 
    cout << (ok ? 'Y' : 'N') << endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
