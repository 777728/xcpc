#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100005;
ll w[N << 2], lz1[N << 2], lz2[N << 2]; // 区间和，首项标记，公差标记
int n, m;

void pushup(int u) { w[u] = w[u << 1] + w[u << 1 | 1]; }

// 打标记：区间 [l, r] 加上首项 k，公差 d 的等差数列
void maketag(int u, int l, int r, ll k, ll d) {
    ll len = r - l + 1;
    w[u] += len * k + len * (len - 1) / 2 * d;
    lz1[u] += k;
    lz2[u] += d;
}

void pushdown(int u, int l, int r) {
    if (!lz1[u] && !lz2[u]) return;
    int mid = (l + r) >> 1;
    // 左子区间
    maketag(u << 1, l, mid, lz1[u], lz2[u]);
    // 右子区间：首项需偏移 (mid + 1 - l) * d
    maketag(u << 1 | 1, mid + 1, r, lz1[u] + lz2[u] * (mid + 1 - l), lz2[u]);
    lz1[u] = lz2[u] = 0;
}

void update(int u, int l, int r, int L, int R, ll k, ll d) {
    if (L <= l && r <= R) {
        // 当前区间左端点 l 相对于操作左端点 L 的偏移
        maketag(u, l, r, k + d * (l - L), d);
        return;
    }
    pushdown(u, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(u << 1, l, mid, L, R, k, d);
    if (R > mid) update(u << 1 | 1, mid + 1, r, L, R, k, d);
    pushup(u);
}

ll query(int u, int l, int r, int p) {
    if (l == r) return w[u];
    pushdown(u, l, r);
    int mid = (l + r) >> 1;
    if (p <= mid) return query(u << 1, l, mid, p);
    else return query(u << 1 | 1, mid + 1, r, p);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        update(1, 1, n, i, i, x, 0); // 初始化单点
    }
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll k, d;
            cin >> l >> r >> k >> d;
            update(1, 1, n, l, r, k, d);
        } else {
            int p; cin >> p;
            cout << query(1, 1, n, p) << '\n';
        }
    }
    return 0;
}