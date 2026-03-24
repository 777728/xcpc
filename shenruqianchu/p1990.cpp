#include <iostream>
using namespace std;
#define maxn 1000005
#define mod 10000
int n;
int f[maxn],g[maxn];
int main(){
   cin>>n;
    g[0] = 0;
    f[0] = f[1] = g[1] = 1;
    for(int i = 2;i <= n;++i){
        f[i] = (f[i-1] + f[i - 2] + (g[i - 2] * 2) % mod) % mod;
        g[i] = (g[i - 1]+f[i - 1]) % mod;
    }
    cout<<f[n] % mod;
}