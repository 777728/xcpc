#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 2010
#define maxm 20005
const int inf = 2147483647;         
int n,m,cnt0;
int dis[maxn],vis[maxn],head[maxn],cnt[maxn];
struct node{
    int nxt,to,dis;
}edge[maxm];

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
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    cnt[1]++;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i;i = edge[i].nxt){
            if(dis[edge[i].to] > dis[u] + edge[i].dis){
                dis[edge[i].to] = dis[u] + edge[i].dis;
                if(!vis[edge[i].to]){
                    vis[edge[i].to] = 1;
                    q.push(edge[i].to);
                    cnt[edge[i].to]++;
                    if(cnt[edge[i].to] > n) return 1;  // 存在负环  
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
    int t;
    cin>>t;
    while(t--){
        init();
        cin>>n>>m;
        for(int i = 1;i <= m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            if(w >= 0)add(v,u,w);
        }
        if(spfa()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
    