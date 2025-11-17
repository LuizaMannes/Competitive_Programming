#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 1e7+7;

vector<bool> is_prime(mx, true);
int lpf[mx], primes[mx], cnt = 0, vis[mx];
void build() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < mx; i++) {
        if (is_prime[i]) {
            lpf[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] < mx; j++) {
            is_prime[i * primes[j]] = 0;
            lpf[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

vector<int> factorize(int n) {
    vector<int> f;
    map<int,int> freq;
    while (n > 1) {
        freq[lpf[n]]++;
        n /= lpf[n];
    }
    for(auto [p,q]: freq) f.push_back(q);
    return f;
}

void solve() {
    int n; cin >> n;
    if(n < 9){
        cout << 0 << endl;
        return;
    }

    build();
    
    int res = 0;
    for (int i = 2; i * i <= n; i++) {
        if (i & 1) {
            if(!vis[i]){
                vector<int> f = factorize(i);
                for(__int128 j = i; j * j <= n; j *= j){
                    int a = 1;
                    for(int k = 0; k < f.size(); k++){
                        f[k] *= 2;
                        a *= f[k] + 1;
                    }
                    if(a < mx) res += is_prime[a];
                    vis[j] = 1;
                }
            }

       }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
