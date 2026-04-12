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
#include<climits>
using namespace std;
int ans = INT_MAX;
int a,b,x,y;
int mem[25][25];

void dfs(int aa,int bb,int tmp){
    if(aa < 0) aa = 0;
    if(bb < 0) bb = 0;
    if(tmp >= ans || (mem[aa][bb] != -1 && mem[aa][bb] <= tmp))return;
    mem[aa][bb] = tmp;
    if(aa <= 0 && bb <= 0){
        ans = min(ans,tmp);
        return;
    }
    dfs(aa - y,bb - y,tmp + 1);
    if(aa > 0) dfs(aa - x ,bb,tmp + 1);
    if(bb > 0) dfs(aa,bb - x,tmp + 1);
}
void solve(){
    memset(mem, -1,sizeof(mem));
    cin>>a>>b>>x>>y;
    if(a < b) swap(a,b);
    dfs(a,b,0);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}