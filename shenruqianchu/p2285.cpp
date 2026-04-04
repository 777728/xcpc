#include<iostream>
#include<cstring>
#define ll long long
#define maxn 10010
using namespace std;
int n,m,ans;
int f[maxn],t[maxn],x[maxn],y[maxn];

int main(){
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        cin>>t[i]>>x[i]>>y[i];
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(f[j] + 1 > f[i] && abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                f[i] = f[j] + 1;
        }
        ans = max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}