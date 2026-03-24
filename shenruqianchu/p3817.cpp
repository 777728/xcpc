#include <iostream>
using namespace std;
#define int long long
#define maxn 100010
int n,x,ans = 0;
int a[maxn];
signed main(){
    cin>>n>>x;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    if(a[1] > x){
        ans += a[1] - x;
        a[1] = x;
    }
    for(int i = 2;i<=n;++i){
        if(a[i] + a[i-1] >x){
            ans+=a[i] + a[i-1] - x;
            a[i] = x - a[i-1];
        }
    }
    cout<<ans;
}