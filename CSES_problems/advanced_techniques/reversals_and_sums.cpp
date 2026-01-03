#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
namespace treap {
    using T = long long; 
    T merge(T a, T b) { return a + b; }
    T neutral = 0;
    struct node_info {
        node_info *l, *r;
        int y, size;
        T val, acc;
        bool rev;
        node_info() { }
        node_info(T _val)
            : l(0), r(0), y(rng()), size(0), val(_val), acc(0), rev(false) { }
    };
    using node = node_info *;
    node root = 0;
    inline int size(node t) { return t ? t->size : 0; }
    inline T acc(node t) { return t ? t->acc : 0; }
    inline bool rev(node t) { return t ? t->rev : false; }
    inline void push(node t) {
        if (!t) return;
        if (rev(t)) {
            t->rev = false;
            swap(t->l, t->r);
            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;
        }
    }
    inline void pull(node t) {
        if (t) {
            push(t->l), push(t->r);
            t->size = size(t->l) + size(t->r) + 1;
            t->acc = merge(t->val, merge(acc(t->l), acc(t->r)));
        }
    }
    void merge(node &t, node L, node R) {
        push(L), push(R);
        if (!L || !R) {
            t = L ? L : R;
        } else if (L->y > R->y) {
            merge(L->r, L->r, R);
            t = L;
        } else {
            merge(R->l, L, R->l);
            t = R;
        }
        pull(t);
    }
    void split(node t, int pos, node &L, node &R, int add = 0) {
        if (!t) {
            L = R = nullptr;
        } else {
            push(t);
            int imp_key = add + size(t->l);
            if (pos <= imp_key) {
                split(t->l, pos, L, t->l, add);
                R = t;
            } else {
                split(t->r, pos, t->r, R, imp_key + 1);
                L = t;
            }
        }
        pull(t);
    }
    inline void insert(node to, int pos) {
        node L, R;
        split(root, pos, L, R);
        merge(L, L, to);
        merge(root, L, R);
    }
    inline T query(int l, int r) {
        if (l > r) return neutral;
        node L1, L2, R1, R2;
        split(root, r + 1, L1, R1);
        split(L1, l, L2, R2);
        T ans = acc(R2);
        merge(L1, L2, R2);
        merge(root, L1, R1);
        return ans;
    }
    inline void reverse(int l, int r) {
        if (l > r) return;
        node L1, L2, R1, R2;
        split(root, r + 1, L1, R1);
        split(L1, l, L2, R2);
        R2->rev ^= 1;
        merge(L1, L2, R2);
        merge(root, L1, R1);
    }
    inline void insert(int pos, int val) { insert(new node_info(val), pos); }
}

void solve() {
    int n, q; cin >> n >> q;
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        treap::insert(i, a);
    }

    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b;
            a--;b--;
            treap::reverse(a,b);
        }else{
            int a, b; cin >> a >> b;
            a--;b--;
            cout << treap::query(a,b) << endl;
        }
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

