#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    ll dp = 0;
    ll best[2] = {LLONG_MIN, LLONG_MIN};
    
    for (int i = 1; i <= n; i++) {
        int p = (a[i] % 2 + 2) % 2;  
        ll new_dp = dp;
        if (best[p] != LLONG_MIN) {
            new_dp = max(new_dp, best[p] + a[i]);
        }
        best[p] = max(best[p], dp + a[i]);
        dp = new_dp;
    }
    
    cout << dp << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}