#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define maxn 200010
int ans = 0;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    int i;
    for(i = 1;i <= t;i++){
        ans += i;
        if(ans >= t) break;
    }
    cout<<i<<endl;
    return 0;
}
