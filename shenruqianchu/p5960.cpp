#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 50005
const int inf = 2147483647;         
int n,m,cnt0;
int dis[maxn],vis[maxn],head[maxn],cnt[maxn];
struct node{
    int nxt,to,dis;
}edge[maxn];

void add(int a,int b,int c){
    edge[++cnt0].to = b;     // 第cnt0条边指向b
    edge[cnt0].dis = c;      // 边权为c
    edge[cnt0].nxt = head[a];
    head[a] = cnt0;
}

bool spfa(){
    queue<int>q;
    for(int i = 1;i <= n;i++){
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(0);
    dis[0] = 0;
    vis[0] = 1;
    cnt[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i;i = edge[i].nxt){
            int v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].dis){
                dis[v] = dis[u] + edge[i].dis;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v] > n + 1) return 1;  // 存在负环  
                }
            }
        }
    }
    return 0;
}

void init(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(head,0,sizeof(head));
    cnt0 = 0;
}

int main(){
    ios::sync_with_stdio(false);
        cin>>n>>m;
        for(int i = 1;i <= m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            add(v,u,w);
        }
        for(int i = 1;i <= n;i++){
            add(0,i,0);  // 从虚拟节点0出发，连接所有节点，边权为0
        }
        if(!spfa()){
            for(int i = 1;i <= n;i++){
                cout<<dis[i]<<" ";
            }
        }
        else cout<<"NO\n";
    return 0;
}
    