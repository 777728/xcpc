#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve() {
    int n, k;
    int ans = 0;  
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];

    if(k == 1){
        int x = a[b[0] - 1]; 
        int cntL = 0, cntR = 0;
        bool in = false;

        for (int i = b[0] - 1 - 1; i >= 0; i--) {
            if (a[i] != x) {
                if (!in) { cntL++; in = true; }
            } else {
                in = false;
            }
        }

        in = false;
        for (int i = b[0] - 1 + 1; i < n; i++) {
            if (a[i] != x) {
                if (!in) { cntR++; in = true; }
            } else {
                in = false;
            }
        }

        cout << 2 * max(cntL, cntR) << "\n";
    }
    else {
        int x = a[b[0] - 1]; 
        bool in = false;

        for(int i = 0;i < n; i++){
            if (a[i] != x) {
                if (!in) { ans++; in = true; }
            } else {
                in = false;
            }
         }
        cout << ans << endl;
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}