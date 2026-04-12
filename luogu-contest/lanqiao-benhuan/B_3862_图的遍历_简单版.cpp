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
#define maxn 1010
int n,m;
vector<int>g[maxn];
int fa[maxn];
int a[maxn];

void dfs(int x){
    int ans = 0;
    for(int i = 0;i < g[x].size();i++){
        if(g[x][i] == fa[x]) continue;
        fa[g[x][i]] = x;
        ans = max(ans,g[x][i]);
        dfs(g[x][i]);
    }
    a[x] = ans;
}
void solve(){
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fa[1] = 1;
    dfs(1);
    for(int i = 1;i <= n;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}