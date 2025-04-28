#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int maxn=2e5+5;
int seg[4*maxn];

void update(int p,int r,int L,int R){
    if(L > r) return;

    if(r>=R){
        seg[p]++;
        return;
    }

    int mid=(R+L)/2;
    update(2*p,r,L,mid);
    update(2*p+1,r,mid+1,R);
}

int inter = 0;
void query(int p, int L, int R,int r){
    inter+=seg[p];
    if(L == R) return;
    int mid=(R+L)/2;
    if(r<=mid)query(2*p, L, mid, r);
    else query(2*p + 1, mid + 1, R, r);
}

void solve() {
    int x,y; cin >> x >> y;
    int h,v; cin >> h >> v;
    vector<pair<int,int>> ho;
    vector<pair<int,int>> ve;
    for(int i=0;i<h;i++){
        int a,b; cin >> a >> b;
        ho.emplace_back(a,b);
    }
    for(int i=0;i<v;i++){
        int c,d; cin >> c >> d;
        ve.emplace_back(c,d);
    }
    sort(ho.begin(),ho.end());
    sort(ve.begin(),ve.end());
    
    map<int,int> mapa_do_tesouro;
    vector<int> arr;
    for(int i=0;i<h;i++){
        arr.push_back(ho[i].second);
    }
    for(int i=0;i<h;i++){
        mapa_do_tesouro[arr[i]]=i;
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<h;i++){
        arr[i]=mapa_do_tesouro[arr[i]];
    }
    
    for(int i=0;i<h;i++){
        query(1, 0,arr.size()-1, arr[i]);
        update(1,arr[i],0,arr.size()-1);
    }

    mapa_do_tesouro.clear();
    arr.clear();
    for(int i=0;i<4*maxn;i++) seg[i]=0;

    for(int i=0;i<v;i++){
        arr.push_back(ve[i].second);
    }

    for(int i=0;i<v;i++){
        mapa_do_tesouro[arr[i]]=i;
    }
    
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<v;i++){
        arr[i]=mapa_do_tesouro[arr[i]];
    }
    
    for(int i=0;i<v;i++){
        query(1,0,arr.size()-1,arr[i]);
        update(1,arr[i],0,arr.size()-1);
    }
   
    int hiv=((h+1)*(v+1))+inter;
    cout << hiv << endl;
    

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

