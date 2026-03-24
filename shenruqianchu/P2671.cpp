#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200010
#define int long long
const int mod = 10007;
int a[maxn],b[maxn];
int s1[maxn][2],s2[maxn][2];    
signed main(){
    int n,m;
    int ans = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>b[i];///color
        s1[b[i]][i%2]++;//编号+颜色
        s2[b[i]][i % 2] = (s2[b[i]][i % 2] + a[i]) % mod;//编号+颜色
    }
    for(int i = 1;i <= n;i++){
        ans += i * (s2[b[i]][i % 2] + a[i] * (s1[b[i]][i % 2]-2) % mod) % mod;
        ans %= mod;
    }
    cout<<ans<<endl;

}