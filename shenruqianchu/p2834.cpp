#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1010
const int mod = 1000000007;
int f[10010],a[1010];
int main(){
    int n,w;
    cin>>n>>w;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = a[i]; j <= w;j++){
            f[j] = (f[j] + f[j - a[i]]) % mod;
        }
    }
    cout<<f[w];
}