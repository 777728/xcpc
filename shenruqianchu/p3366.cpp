#include<iostream>
#include<queue>
#define maxn 400500
const int inf = 2147483647;  
using namespace std;

int h[maxn],cnt,dis[maxn],tot,ans;
bool vis[maxn];

struct edge{
    int to,nxt,val;
}e[maxn];

struct node {
    int pos, dis;
    bool operator < (const node& b) const {
        return dis > b.dis;  // 小根堆：dis 小的优先级高
    }
}tmp;

priority_queue<node>q;

void add(int from,int to,int value){
    cnt++;
    e[cnt].nxt = h[from];
    e[cnt].to = to;
    e[cnt].val = value;
    h[from] = cnt;
}
int n,m;
void prim(){
    for(int i = 1;i <= n;i++){
        dis[i] = inf;
    }
    dis[1] = 0;
    tmp.dis = 0;
    tmp.pos = 1;
    q.push(tmp); 
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        int u = tmp.pos,d = tmp.dis;
        if(vis[u]) continue;
        tot++;
        vis[u] = 1;
        ans += dis[u];
        for(int i = h[u];i;i = e[i].nxt){
            int v = e[i].to;
            int w = e[i].val;
            if(dis[v] > w){
                tmp.dis = dis[v] = w;
                tmp.pos = v;
                q.push(tmp);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);

    }
    prim();
    if(tot == n) cout<<ans;
    else puts("orz");
    return 0;
    
}