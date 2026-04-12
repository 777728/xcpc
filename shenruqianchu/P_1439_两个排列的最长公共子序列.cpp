#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int pos[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i; // Record position in P1
    }

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int p = pos[x]; // Map P2 value to P1's index

        auto it = lower_bound(lis.begin(), lis.end(), p);
        if (it == lis.end()) lis.push_back(p);
        else *it = p;
    }

    cout << lis.size() << "\n";
    return 0;
}