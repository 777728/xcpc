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
using namespace std;
using ll = long long;

const int MOD = 676767677;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    // p[t] = 时刻 < t 已坐下的人数
    vector<int> p(m + 1, 0);
    for (int i = 0; i < m; ++i) p[i + 1] = p[i] + cnt[i];

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) continue; // a[i]=0 只有一种取法，不影响乘积

        int min_nb = INT_MAX;
        if (i > 0)     min_nb = min(min_nb, b[i - 1]);
        if (i < n - 1) min_nb = min(min_nb, b[i + 1]);

        if (b[i] <= min_nb) { cout << "0\n"; return; }

        ll ways = (b[i] == min_nb + 1) ? p[b[i]] : cnt[b[i] - 1];
        ans = ans * ways % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}