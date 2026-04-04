#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
int dep[maxn],head[maxn],sizee[maxn],f[maxn];
int n,center,sum = 0;
vector<int>g[maxn];
queue<int>q;

void getcenter(int u,int fa){
    sizee[u] = 1;
    f[u] = 0;
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(v == fa) continue;
        getcenter(v,u);
        sizee[u] += sizee[v];
        f[u] = max(f[u],sizee[v]);
    }
    f[u] = max(f[u],n - sizee[u]);
    //找到每一个节点的最大子树
    if(f[u] < f[center] || (f[u] == f[center] && u < center)) 
    center = u;//更新目前最小的最大子树
}
void bfs(){
    q.push(center);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i];
            if(dep[v] || v == center) continue;//若非 0，表示 v 已访问过（距离已计算），跳过。
            dep[v] = dep[u] + 1;
            sum += dep[v];
            q.push(v);
        }
    }
}
int main(){
    cin>> n ;
    for(int i = 1;i < n;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    center = 0,f[0] = inf;
    getcenter(1,0);
    bfs();
    cout<<center<<" "<<sum;
    
}