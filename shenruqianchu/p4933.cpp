#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
const int INF = 2e9;
#define mod 998244353
#define maxv 20010
int f[maxn][maxv * 2],n,a[maxn],ans;


int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        for(int j = 1;j < i;j ++){
            (f[i][a[i] - a[j] + maxv] += f[j][a[i] - a[j] + maxv] + 1) %= mod;
            ans = (ans + f[j][a[i] - a[j] + maxv] + 1) % mod;
        }
    }
    cout<<(ans + n) % mod ;
}