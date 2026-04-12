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
vector<int>a(15);
vector<bool>vis(15,0);
void dfs(int now){
    
    if(now > k){
        for(int i = 1;i <= k;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        a[now] = i;
        vis[i] = 1;
        dfs(now + 1);
        vis[i] = 0;
    }
}
void solve(){
    cin>>n>>k;
    dfs(1);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}