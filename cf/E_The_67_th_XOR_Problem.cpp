#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j){
            ans = max(ans, a[i] ^ a[j]);
        }
    }
    
    cout << ans << "\n";
}

signed main() {
    // 加速 IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}