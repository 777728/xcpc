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

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int n,a[maxn],f[maxn][2];

void dfs(int u,int fa){
    f[u][0] = 0,f[u][1] = a[u];
    for(auto v:g[u]){
        if(v != fa){
            dfs(v,u);
            f[u][0] += max(f[v][0],f[v][1]);
            f[u][1] += f[v][0];
        }
    }
}
void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout << max(f[1][0],f[1][1]) << '\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}