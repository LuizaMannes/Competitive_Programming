#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;cin >> n;
    string s; cin >> s;
    pair<int,int> r,h;
    vector<char> res;
    int cr=0,ch=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='N'){
            if(r.first<h.first){
                r.first++;
                res.push_back('R');
                cr++;
            }else if(r.first>h.first){
                h.first++;
                res.push_back('H');
                ch++;
            }else{
                if(cr<=ch){
                    r.first++;
                    res.push_back('R');
                    cr++;
                }else{
                    h.first++;
                    res.push_back('H');
                    ch++;
                }
            }
        }
        if(s[i]=='S'){
            if(r.first>h.first){
                r.first--;
                res.push_back('R');
                cr++;
            }else if(r.first<h.first){
                h.first--;
                res.push_back('H');
                ch++;
            }else{
                if(cr<=ch){
                    r.first--;
                    res.push_back('R');
                    cr++;
                }else{
                    h.first--;
                    res.push_back('H');
                    ch++;
                }
            }
        }
        if(s[i]=='E'){
            if(r.second<h.second){
                r.second++;
                res.push_back('R');
                cr++;
            }else if (r.second>h.second){
                h.second++;
                res.push_back('H');
                ch++;
            }else{
                if(cr<=ch){
                    r.second++;
                    res.push_back('R');
                    cr++;
                }else{
                    h.second++;
                    res.push_back('H');
                    ch++;
                }
            }
        }
        if(s[i]=='W'){
            if(r.second>h.second){
                r.second--;
                res.push_back('R');
                cr++;
            }else if(r.second<h.second){
                h.second--;
                res.push_back('H');
                ch++;
            }else{
                if(cr<=ch){
                    r.second--;
                    res.push_back('R');
                    cr++;
                }else{
                    h.second--;
                    res.push_back('H');
                    ch++;
                }
            }
        }
    }
    if(r.first==h.first && r.second==h.second && cr>0 && ch>0){
        for(auto c:res) cout << c;
        cout << endl;
    }else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

