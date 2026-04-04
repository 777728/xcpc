#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 100010
int n,q,c[maxn],d[maxn],fa[maxn];
vector<int>g[maxn];
bool vis[25];
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
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    if(d[u] < d[v]) swap(u ,v);
    while(d[u] != d[v]){
        if(!vis[c[u]])cnt++;
        vis[c[u]] = 1;
        u = fa[u];//将 u 调整到与 v 同一深度
    } 
    while(u != v){
        if(!vis[c[u]])cnt++;
        vis[c[u]] = 1;
        if(!vis[c[v]])cnt++;
        vis[c[v]] = 1;
        u = fa[u];
        v = fa[v];//同时向上调整 u 和 v，直到它们相等，此时的 u（或 v）就是它们的最近公共祖先 
    }
    // 加上 LCA 节点的零食
    if (!vis[c[u]]) {
        vis[c[u]] = 1;
        cnt++;
    }
    return cnt;
}
int main(){
    cin>>n>>q;
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    for(int i = 1;i < n;i++){
        int u, v;
        cin>>u>>v;
        addedge(u,v);
    }
    vis[1] = 1;
    dfs(1);
    for(int i = 1;i <= q;i++){
        int s,t;
        cin>>s>>t;
        cout<<query(s,t)<<endl;
        
    }
}