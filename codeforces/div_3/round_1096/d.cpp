#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'
using ll = long long;

struct Manacher {
    int n;
    ll count;
    vector<int> d1, d2, man;
    ll solve(const vector<int> &s) {
        n = int(s.size()), count = 0;
        solve_odd(s);
        solve_even(s);
        man.assign(2 * n - 1, 0);
        for (int i = 0; i < n; i++) man[2 * i] = 2 * d1[i] - 1;
        for (int i = 0; i < n - 1; i++) man[2 * i + 1] = 2 * d2[i + 1];
        return count;
    }
    void solve_odd(const vector<int> &s) {
        d1.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
            count += d1[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
    }
    void solve_even(const vector<int> &s) {
        d2.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            count += d2[i] = k--;
            if (i + k > r) l = i - k - 1, r = i + k;
        }
    }
    bool query(int i, int j) {
        assert(man.size());
        return man[i + j] >= j - i + 1;
    }
} mana;

void solve() {
    int n; cin >> n;

    vector<int> ar(2 * n);
    int p1 = -1, p2 = -1;
    for(int i = 0; i < 2 * n; i++){
        cin >> ar[i];
        if(ar[i] == 0 and p1 == -1) p1 = i;
        if(ar[i] == 0) p2 = i;
    }
    mana.solve(ar);

    int l = p1, r = p1;
    vector<int> f(n + 1);
    while(l >= 0 and r < 2 * n){
        if(ar[l] == ar[r]) {
            f[ar[l]]++;
            l--;
            r++;
        }else {
            break;
        }
    }

    int m = 0;
    while(f[m] >= 1) m++;
    //cout << m << endl;

    l = p2, r = p2;
    vector<int> f2(n + 1);
    while(l >= 0 and r < 2 * n){
        if(ar[l] == ar[r]) {
            f2[ar[l]]++;
            l--;
            r++;
        }else {
            break;
        }
    }


    int mm = 0;
    while(f2[mm] >= 1) mm++;
    m = max(m, mm);
    //cout << m << endl;

    if(mana.query(p1, p2)){
        l = p1, r = p2;
        vector<int> f3(n + 1);
        for(int i = p1; i <= p2; i++){
            f3[ar[i]]++;
        }
        while(l >= 0 and r < 2 * n){
            if(ar[l] == ar[r]) {
                f3[ar[l]]++;
                l--;
                r++;
            }else {
                break;
            }
        }
        mm = 0;
        while(f3[mm] >= 1) mm++;

        m = max(m, mm);
    }

    cout << m << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;cin >> tc; while(tc--) solve();
}

