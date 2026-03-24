#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int a[5005];

struct money{
    int m;
    int v;
}coin[109];

bool cmp(money x,money y){
    return x.v * y.m > x.m * y.v;
}
signed main(){
    int n,t;
    cin>>n>>t;
    for(int i = 0;i < n;i++){
        cin>>coin[i].m>>coin[i].v;
    }
    sort(coin ,coin + n ,cmp);
    int c = t;
    int i;
    double ans = 0;
    for(i = 0;i < n;i++){
        if(coin[i].m > c) break;
        else{
          c -= coin[i].m;
            ans += coin[i].v;
        }
    }
    if(coin[i].m > c) ans += 1.0 * c / coin[i].m * coin[i].v;
    cout<<fixed<<setprecision(2)<<ans;
}