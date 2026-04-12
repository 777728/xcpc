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
int n,k;
void dfs(int now,int xuan){
    vector<int>a(n + 1);
    if(now > n) return;
    if(xuan > k){
        for(int i = 1;i <= k;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(now == i) continue;
        dfs(now + 1,xuan);
        a[now] = i;
        dfs(now + 1,xuan + 1);
        a[now] = 0;
    }
}
void solve(){
    cin>>n>>k;
    dfs(0,0);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}