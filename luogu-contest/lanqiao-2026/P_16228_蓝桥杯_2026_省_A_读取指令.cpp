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
    
    vector<long long> s;
    vector<long long> a(120);
    
    void solve() {
        int n, c;
        long long w;
        cin >> n >> c >> w;
      
        
    
        if (w % c != 0 || w / c > (long long)(n + 1) * n / 2) 
            cout << -1 << endl;
       
        return;  
    }
    
    int main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }