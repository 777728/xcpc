#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define int long long
#define maxn 100010
const int mod = 1000000007;
int n,ans = 0;
int a[maxn],cnt[200010];
set<int> s;
signed main(){
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }
    
    // 把set的值转到vector里
    vector<int> b(s.begin(), s.end());
    int m = b.size();
    
    for(int i = 0;i < m;i++){
        for(int j = i;j < m;j++){
            int tmps = b[i] + b[j];
            if(tmps > 200000 || cnt[tmps] < 2) continue;
            
            int ways1, ways2;
            if(i == j) {
                ways1 = cnt[b[i]] * (cnt[b[i]] - 1) / 2 % mod;
            } else {
                ways1 = cnt[b[i]] * cnt[b[j]] % mod;
            }
            ways2 = cnt[tmps] * (cnt[tmps] - 1) / 2 % mod;
            ans = (ans + ways1 * ways2) % mod;
        }
    }
    cout << ans;
    return 0;
}