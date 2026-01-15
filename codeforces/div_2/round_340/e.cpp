#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
typedef pair<int, int> ii;
const int mx = 1e6 + 5;
int k, block_sz, ar[mx], freq[mx], ans, b; 

namespace mo {
    struct query {
        int l, r, idx;
        bool operator<(query q) const {
            int _l = l / block_sz;
            int _ql = q.l / block_sz;
            return ii(_l, _l & 1 ? -r : r) < ii(_ql, _ql & 1 ? -q.r : q.r);
        }

        query(int l, int r, int idx): l(l), r(r), idx(idx){}
    };
    vector<query> queries;

    void build(int n) {
        block_sz = (int)sqrt(n);
    }
    inline void add_query(int l, int r) {
        queries.push_back({l, r, (int)queries.size()});
    }
    inline void remove(int idx) {
        freq[b]--;
        b ^= ar[idx];
        ans -= freq[b ^ k];
    }
    inline void add(int idx) {
        b ^= ar[idx];
        ans += freq[b ^ k];
        freq[b]++;
    }
    inline int get_answer() {
        return ans;
    }

    vector<int> run() {
        vector<int> answers(queries.size());
        sort(queries.begin(), queries.end());
        int L = 0;
        int R = -1;
        for (query q : queries) {
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (L < q.l) remove(L++);
            while (R > q.r) remove(R--);
            answers[q.idx] = get_answer();
        }
        return answers;
    }

};

void solve() {
    int n, m; cin >> n >> m >> k;
    mo::build(n);
    for(int i = 0; i < n; i++) cin >> ar[i];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

