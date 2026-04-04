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
    for(int i = 1;i <= w;i++){
        for(int j = 1; j <= n;j++){
            if(i >= a[j]) f[i] = (f[i] + f[i - a[j]]) % mod;
        }
    }
    cout<<f[w];
}