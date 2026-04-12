#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#define ls i << 1
#define rs i << 1 | 1
using namespace std;

const int N = 1e5 + 5;

int n, m, r, p, cnt, tot;
int a[N], id_val[N];
int head[N], dep[N], siz[N], hson[N], fa[N];
int top[N], id[N];

struct Edge {
    int to, next;
} e[N << 1];

void add(int x, int y) {
    e[++tot] = {y, head[x]};
    head[x] = tot;
}

// ---------- 线段树 ----------
struct Node {
    int l, r;
    long long sum, add;
} t[N << 2];

void pushup(int i) {
    t[i].sum = (t[ls].sum + t[rs].sum) % p;
}

void build(int i, int l, int r) {
    t[i].l = l, t[i].r = r;
    if (l == r) {
        t[i].sum = id_val[l] % p;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(i);
}

void spread(int i) {
    if (t[i].add) {
        t[ls].sum = (t[ls].sum + t[i].add * (t[ls].r - t[ls].l + 1)) % p;
        t[rs].sum = (t[rs].sum + t[i].add * (t[rs].r - t[rs].l + 1)) % p;
        t[ls].add = (t[ls].add + t[i].add) % p;
        t[rs].add = (t[rs].add + t[i].add) % p;
        t[i].add = 0;
    }
}

void change(int i, int l, int r, int v) {
    if (l <= t[i].l && t[i].r <= r) {
        t[i].sum = (t[i].sum + 1LL * v * (t[i].r - t[i].l + 1)) % p;
        t[i].add = (t[i].add + v) % p;
        return;
    }
    spread(i);
    int mid = (t[i].l + t[i].r) >> 1;
    if (l <= mid) change(ls, l, r, v);
    if (r > mid) change(rs, l, r, v);
    pushup(i);
}

long long query(int i, int l, int r) {
    if (l > t[i].r || r < t[i].l) return 0;
    if (l <= t[i].l && t[i].r <= r) return t[i].sum;
    spread(i);
    return (query(ls, l, r) + query(rs, l, r)) % p;
}

// ---------- 树剖 ----------
void dfs1(int x, int f) {
    siz[x] = 1, fa[x] = f, dep[x] = dep[f] + 1;
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].to;
        if (y == f) continue;
        dfs1(y, x);
        siz[x] += siz[y];
        if (siz[hson[x]] < siz[y] || !hson[x]) hson[x] = y;
    }
}

void dfs2(int x, int t) {
    top[x] = t, id[x] = ++cnt, id_val[cnt] = a[x];
    if (!hson[x]) return;
    dfs2(hson[x], t);
    for (int i = head[x]; i; i = e[i].next) {
        int y = e[i].to;
        if (y != fa[x] && y != hson[x]) dfs2(y, y);
    }
}

void changeto(int x, int y, int z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        change(1, id[top[x]], id[x], z);
        x = fa[top[x]];
    }
    if (id[x] > id[y]) swap(x, y);
    change(1, id[x], id[y], z);
}

long long queryto(int x, int y) {
    long long ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + query(1, id[top[x]], id[x])) % p;
        x = fa[top[x]];
    }
    if (id[x] > id[y]) swap(x, y);
    ans = (ans + query(1, id[x], id[y])) % p;
    return ans;
}

// ---------- main ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);

    while (m--) {
        int opt, x, y, z;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> z;
            changeto(x, y, z);
        } else if (opt == 2) {
            cin >> x >> y;
            cout << queryto(x, y) << '\n';
        } else if (opt == 3) {
            cin >> x >> z;
            change(1, id[x], id[x] + siz[x] - 1, z);
        } else {
            cin >> x;
            cout << query(1, id[x], id[x] + siz[x] - 1) << '\n';
        }
    }
    return 0;
}