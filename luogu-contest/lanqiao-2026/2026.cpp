#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
int ans = 0;
void haoshu(int x){
    int vis2 = 0;
    int vis0 = 0;
    int vis6 = 0;
    int temp;
    while(x != 0){
        temp = x % 10;
        x /= 10;
        if(temp == 2) vis2++;
        if(temp == 0) vis0++;
        if(temp == 6) vis6++;
        if(vis2 > 2||vis0 > 1||vis6 > 1){
            break;
        }
    }
    if(vis2 == 2&&vis0 == 1&&vis6 == 1) ans++;
}
void solve(){
    for(int i = 1;i <= 20262026;i++){
        haoshu(i);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}