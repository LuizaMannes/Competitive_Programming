    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int K = 22, maxn = 1e6 + 50;
    int LOG[maxn];
    vector<vector<int>> st1(K), st2(K);
    vector<int> pref;

    int queryst1(int l, int r){
        int g = LOG[r - l + 1];
        return max(st1[g][l], st1[g][r - (1 << g) + 1]);
    }

    int queryst2(int l, int r){
        int g = LOG[r - l + 1];
        return min(st2[g][l], st2[g][r - (1 << g) + 1]);
    }

    int query(int l, int r, int n){
        if(queryst2(l, r) - (l != 0 ? pref[l-1] : 0)  < 0){
            int res = l;
            for(int i = K - 1; i >= 0; i--){
                if(res + (1 << i) < n && queryst2(l, res + (1 << i)) - (l != 0 ? pref[l-1] : 0)  >= 0)
                    res += (1 << i);
            }
            int ans = queryst1(l, res) - (l != 0 ? pref[l-1] : 0);
            return max(ans + 2, 2);
        }else{
            return queryst1(l, r) + 1 - (l != 0 ? pref[l-1] : 0);
        }
    }

    void solve() {
        int n, q; cin >> n >> q;
        for(int i = 0; i < K; i++){
            st1[i].assign(n, 0);
            st2[i].assign(n, 0);
        }
        pref.assign(n, 0);
        string s; cin >> s;
        pref[0] = (s[0] == '/' ? -1 : 1);
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + (s[i] == '/' ? -1 : 1);
        
        for(int i = 0; i < n; i++)
            st1[0][i] = st2[0][i] = pref[i];
        for(int i = 1; i < K; i++){
            for(int j = 0; j + (1 << i) <= n; j++){
                st1[i][j] = max(st1[i-1][j], st1[i-1][j + (1 << (i-1))]);
                st2[i][j] = min(st2[i-1][j], st2[i-1][j + (1 << (i-1))]);
            }
        }
        while(q--){
            int l, r; cin >> l >> r;
            --l, --r;
            cout << query(l, r, n) << '\n';
        }
    }

    signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0);    
        int t; cin >> t;
        LOG[0] = 0;
        LOG[1] = 0;
        for(int i = 2; i < maxn; i++)
            LOG[i] = LOG[i/2] + 1;
        while (t--) solve();
    }