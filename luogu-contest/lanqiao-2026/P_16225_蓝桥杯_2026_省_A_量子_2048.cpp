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
const int mod = 998244353;
bool a[2029][2029],vis[2029][2029];
long long ans = 0;
bool check1(int x,int y){
    int ji= 0;
    for(int i = 1;i <= 2028;i++){
        if(a[x][i] == 1) ji++;
    }
    if(ji % 2 == 1) return 1;
    else return 0;
}
bool check2(int x,int y){
    int ji= 0;
    for(int i = 1;i <= 2028;i++){
        if(a[i][y] == 1) ji++;
    }
    if(ji % 2 == 1) return 1;
    else return 0;
}
bool check3(int x,int y){
    if((a[x][y] + a[x - 1][y] + a[x][y - 1] + a[x - 1][y - 1]) % 2 == 1)return 1;
    return 0;
}
void dfs(int x,int y){
    if(x > 2028 && y > 2028) {
        ans = (ans + 1) % mod;
        return;
    }
    if(vis[x][y]) return;
    if(x > 2028 || y > 2028) return;
    if(y == 2028 && !check1(x,2028)) return;
    if(x == 2028 && !check2(2028,y)) return;
    if(x != 1 && y!= 1 && !check3(x,y)) return;
    vis[x][y] = 1;
    a[x][y] = 0;
    dfs(x + 1,y);
    dfs(x ,y + 1);
    
    a[x][y] = 1;
    dfs(x + 1,y);
    dfs(x ,y + 1);
}
void solve(){
    dfs(1,1);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}