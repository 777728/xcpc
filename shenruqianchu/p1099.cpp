#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int n,m,ans,d,dis[N],fa[N];
vector<int>g[N];
queue<int>q;
void addedge(int u ,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void bfs(int u){
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dis[u] <= d) ans++;
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i];
            if(v == fa[u])continue;
            fa[v] = u;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
}
int main(){
    cin>> n >> d;
    for(int i = 1;i < n;i++){
        int u, v;
        cin>>u>>v;
        addedge(u,v);

    }
    bfs(1);
    cout<<ans - 1;
}