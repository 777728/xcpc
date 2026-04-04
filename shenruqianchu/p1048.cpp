#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1010
const int mod = 1000000007;
int T,m,t,v,f[1010];
int main(){
    for(cin>>T>>m;m--;){
        cin>>t>>v;
        for(int j = T;j >= t;j--){
            f[j] = max(f[j],f[j - t] + v);
        }
    }
    cout<<f[T];
}