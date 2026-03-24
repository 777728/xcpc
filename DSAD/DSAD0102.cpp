#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define maxn 200010
int ans = 0;
int a[maxn];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    a[1] = 1;
    ans = 1;
    if(t == 1){
        cout<<ans<<endl;
        return 0;
    }
    for(int i = 2;i <= t;i++){
        a[i] = a[i - 1] * i;
        ans += a[i];
    }
    cout<<ans<<endl;
    return 0;
}
