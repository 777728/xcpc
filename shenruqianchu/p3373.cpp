#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int p = 571373;
const int N = 1000005;
const ll INF_SET = 2e9 + 7; // Set 标记无效值 (|x|<=1e9)
const ll INF_MIN = -2e18;   // 查询初始最小值

ll w[N << 2], lz_add[N << 2], lz_set[N << 2];
int n, q;

void pushup(int u) { w[u] = (w[u << 1]+ w[u << 1 | 1]) % p; }

void build(int u, int l, int r) {
    lz_set[u] = INF_SET; lz_add[u] = 0; // 初始化标记
    if (l == r) { cin >> w[u]; return; }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

// 应用 Set 标记
void apply_set(int u, ll v) {
    w[u] = v;
    lz_set[u] = v;
    lz_add[u] = 0; // Set 覆盖 Add
}

// 应用 Add 标记
void apply_add(int u, ll v) {
    w[u] += v;
    if (lz_set[u] != INF_SET) lz_set[u] += v; // 修改 pending 的 Set 值
    else lz_add[u] += v;
}

void pushdown(int u) {
    if (lz_set[u] != INF_SET) {
        apply_set(u << 1, lz_set[u]);
        apply_set(u << 1 | 1, lz_set[u]);
        lz_set[u] = INF_SET;
    }
    if (lz_add[u] != 0) {
        apply_add(u << 1, lz_add[u]);
        apply_add(u << 1 | 1, lz_add[u]);
        lz_add[u] = 0;
    }
}

void update_set(int u, int l, int r, int L, int R, ll v) {
    if (L <= l && r <= R) { apply_set(u, v); return; }
    pushdown(u);
    int mid = (l + r) >> 1;
    if (L <= mid) update_set(u << 1, l, mid, L, R, v);
    if (R > mid) update_set(u << 1 | 1, mid + 1, r, L, R, v);
    pushup(u);
}

void update_add(int u, int l, int r, int L, int R, ll v) {
    if (L <= l && r <= R) { apply_add(u, v); return; }
    pushdown(u);
    int mid = (l + r) >> 1;
    if (L <= mid) update_add(u << 1, l, mid, L, R, v);
    if (R > mid) update_add(u << 1 | 1, mid + 1, r, L, R, v);
    pushup(u);
}

ll query(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R) return w[u];
    pushdown(u);
    int mid = (l + r) >> 1;
    ll res = INF_MIN;
    if (L <= mid) res = max(res, query(u << 1, l, mid, L, R));
    if (R > mid) res = max(res, query(u << 1 | 1, mid + 1, r, L, R));
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        int op, l, r; ll x;
        cin >> op >> l >> r;
        if (op == 1) { cin >> x; update_set(1, 1, n, l, r, x); }
        else if (op == 2) { cin >> x; update_add(1, 1, n, l, r, x); }
        else { cout << query(1, 1, n, l, r) << '\n'; }
    }
    return 0;
}