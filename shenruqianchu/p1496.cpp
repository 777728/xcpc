#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 20010
#define int long long
int n,a[maxn],b[maxn],f[maxn * 2],dtop,ctop,d[maxn * 2];
int ans = 0;
int c[maxn * 2];

signed main(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i];
        d[++dtop] = a[i];
        d[++dtop] = b[i];
    }
    sort(d + 1,d + dtop + 1);
    for(int i = 1;i <= dtop;i++){
        if(d[i] != d[i - 1] || i == 1) c[++ctop] = d[i];
    }
    for(int i = 1;i <= n;++i){
        int x = lower_bound(c + 1,c + ctop + 1,a[i]) - c;
        int y = lower_bound(c + 1,c + ctop + 1,b[i]) - c;
        for(int j = x;j < y;j++){
            f[j] = 1;
        }
    }
    for(int i = 1;i < ctop;i++){
        if(f[i]) ans+=c[i+1] - c[i];
    }
    cout<<ans;
}