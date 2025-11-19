#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define endl '\n'

const int M = 1e7 + 5;
vector<bool> is_prime(M, true);
vector<int> mobius(M, 1);
void build() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < M; i++) {
        if (is_prime[i]){
            mobius[i] = -1;
            for (int j = i + i; j < M; j += i){
                is_prime[j] = 0;
                if((j / i) % i == 0) mobius[j] = 0;
                else mobius[j] *= -1;
            }
        }
    }
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    build();

    long long res = 0;
    for(int i = 1; i < M; i++){
        res += mobius[i] * (floor(b / i) - floor((a - 1) / i)) * (floor(d / i) - floor((c - 1) / i));
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

