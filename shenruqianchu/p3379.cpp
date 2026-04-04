#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
int n,m,rt,d[N],fa[N];
vector<int>g[N];
void addedge(int u ,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int u){
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(v == fa[u]) continue;
        fa[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}
int query(int u ,int v){
    if(d[u] < d[v]) swap(u ,v);
    while(d[u] != d[v]) u = fa[u];//将 u 调整到与 v 同一深度
    while(u != v){
        u = fa[u];
        v = fa[v];//同时向上调整 u 和 v，直到它们相等，此时的 u（或 v）就是它们的最近公共祖先
    }
    return u;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> n >> m >> rt;
    for(int i = 1;i < n;i++){
        int u, v;
        cin>>u>>v;
        addedge(u,v);
    }
    dfs(rt);
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<'\n';
    }
}