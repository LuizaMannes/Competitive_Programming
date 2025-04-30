#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int mx = 2e5 + 5;
vector<int> primes;
vector<bool> prime(mx, 1), semiprime(mx);
vector<tuple<int,int,int>> semiprimes(mx);

void primos(){
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= mx; i++){
        if(prime[i]){
            primes.push_back(i);

            for(int j = i * i; j <= mx; j += i){
                prime[j] = 0;
            }
        }
    }
}

void semiprimos(int a){
    int n = a;
    vector<int> fac;
    for(int d: primes){
        if(d * d > n) break;

        while(n % d == 0){
            fac.push_back(d);
            n /= d;
        }
    }

    if(n > 1) fac.push_back(n);

    if(fac.size() == 2){
        tuple<int,int,int> b = {a, fac[0], fac[1]};
        semiprimes[a] = b;
        semiprime[a] = 1;
    }
}


void solve() {
    int n; cin >> n;

    vector<int> ar(n);

    map<int,int> f;
    int cont = 0;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        if(prime[ar[i]]) cont++;
        f[ar[i]]++;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(semiprime[ar[i]]){
            auto [u, j, k] = semiprimes[ar[i]];
            if(j != k) res += f[u] + f[j] + f[k];
            else res += f[u] + f[j];
            f[u]--;
        }
    }

    for(int i = 0; i < n; i++){
        if(prime[ar[i]]){
            res += cont - f[ar[i]];
            f[ar[i]]--;
            cont--;
        }
    }
   
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    primos();
    for(int i = 0; i <= mx; i++){
        semiprimos(i);
    }
    int tc;cin >> tc; while(tc--) solve();
}

