#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool chmax(T &lhs, T rhs) {
    if (lhs < rhs) {
        lhs = rhs;
        return true;
    }
    return false;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    long long max_here = 0LL, ans = 0LL;
    int lst = 1;
    int ll = 1, rr = 1;

    for (int i = 2; i <= n; i++) {
        cout << "? " << lst << ' ' << i << endl;
        cin >> max_here;
        
        if (max_here == -1) exit(0); // 错误终止

        if (chmax(ans, max_here)) {
            ll = lst;
            rr = i;
        }

        // 若收益为 0，说明 v[i] <= v[lst]，更新潜在最小值位置
        if (max_here <= 0) lst = i;
    }

    cout << "! " << ll << ' ' << rr << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}