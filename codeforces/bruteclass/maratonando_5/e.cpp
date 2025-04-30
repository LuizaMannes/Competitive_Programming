#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n;

int pos(int i,int h,int a,int v,vector<int>& ast){
    if(i==n) return 0;
    int pos1=0;
    int pos2=0;
    //cout << h << endl;
    if(ast[i]<h) return pos(i+1,h+(ast[i]/2),a,v,ast)+1;
    if(a){
        pos1=pos(i,h*3,a-1,v,ast); 
    }
    if(v){
        pos2=pos(i,h*2,a,v-1,ast);
    }
    return max(pos1,pos2);
}

void solve() {
    int h; cin >> n >> h;
    vector<int> ast(n);
    for(int i=0;i<n;i++) cin >> ast[i];
    sort(ast.begin(),ast.end());
    int res=0;
    int azul=1;
    int verde=2;
    for(int i=0;i<n;i++){
        if(ast[i]<h){
            h+=ast[i]/2;
            res++;
        }else{
            res+=pos(i,h,azul,verde,ast);
            break;
        }
    }
    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

