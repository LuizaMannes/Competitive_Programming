#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    map<string,int> freq, notas;
    vector<vector<string>> ar(n + 1);
    for(int i = 0;i <= n; i++){
        string s;
        getline(cin, s);
        string aux = "";
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' '){
                ar[i].push_back(aux);
                freq[aux]++;
                aux = "";
                continue;
            }
            aux.push_back(s[j]);
        }
        ar[i].push_back(aux);
        freq[aux]++;
    }

    int m; cin >> m;
    int res = 0;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        int a; cin >> a;
        notas[s] = a;
        //cout << freq[s] << endl;
        res += freq[s] * a;
    }

    cout << res << " ";
    res = 0;
    int ind = 0;
    for(int i = 1; i <= n ;i++){
        int aux = 0;
        for(auto s:ar[i]){
            if(notas[s]) aux += notas[s];
    //        cout << s << " " << freq[s] << " ";
        }
        if(aux >= res){
            res = aux;
            ind = i;
        }
    //    cout << endl;
    }

    cout << ind << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

