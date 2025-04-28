#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

bool check(int mid,vector<pair<int,int>>&quest,int t,vector<int> &inte,int a){
    int aux=0;
    int b=0;
    for(int i=0;i<quest.size();i++){
        if(quest[i].second<=inte[a]){
            aux+=quest[i].first;
            b++; 
        }
        if(aux>t) return false;
    }
    cout << b << endl;
    cout << aux << endl;
    return b>=mid;
}

void solve() {
    int q,n,t; cin >> q >> n >> t;
    vector<pair<int,int>> quest(q);
    for(int i=0;i<q;i++){
        int d,t;cin >> d >> t;
        quest[i].second=d;
        quest[i].first=t;
    }
    vector<int> inte(n);
    for(int i=0;i<n;i++) cin >> inte[i];
    sort(quest.begin(),quest.end());
    vector<int> ans;
    for(int i=0;i<n;i++){
        int l=0;
        int r=quest.size();
        int res=0;
        cout << "i: " << i << endl;
        while(l<=r){
            int mid=(l+r)>>1;
            cout << "mid: " << mid << endl;
            if(check(mid,quest,t,inte,i)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans.push_back(res);
    }
    for(auto c:ans) cout << c << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

