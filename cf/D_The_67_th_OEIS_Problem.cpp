#include <iostream>
#include <vector>
using namespace std;

vector<long long> primes;
const long long MAX_N = 10005;

void init_primes() {
    const int LIMIT = 200000;
    bool not_prime[LIMIT] = {false};
    
    for (int i = 2; i < LIMIT && primes.size() <= MAX_N + 5; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < LIMIT; j += i) {
                not_prime[j] = true;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        long long val = 1LL * primes[i] * primes[i + 1];
        cout << val << (i == n - 1 ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init_primes();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}