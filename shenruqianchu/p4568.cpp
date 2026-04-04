#include<iostream>
#include<queue>
using namespace std;
#define maxn 10500010                    // 最大节点数
const int inf = 2147483647;           // 无穷大（约10^9）
int s,t;

int n,m,k,cnt;                        // n点m边s起点，cnt边计数器
int dis[maxn],h[maxn],to[maxn],val[maxn],nxt[maxn];  // 链式前向星数组
bool vis[maxn];                       // 标记是否已确定最短路

struct node{
    int v,w;
    friend bool operator < (node a,node b){
        return a.w > b.w;
    }
}tmp;
priority_queue<node>q;
// 链式前向星加边：头插法
void add(int a,int b,int c){
    to[++cnt] = b;     // 第cnt条边指向b
    val[cnt] = c;      // 边权为c
    nxt[cnt] = h[a];   // 下一条边是原h[a]
    h[a] = cnt;        // a的头指针指向新边
}

void dijkstra(){
    int total = ( k + 1) * n;

    for(int i = 1;i <= total;i++) dis[i] = inf;  // 初始化距离为无穷
    dis[s] = 0;                               // 起点距离为0
    tmp.v = s, tmp.w = 0;
    q.push(tmp);
    
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u];i;i = nxt[i]){
            if(dis[to[i]] > (long long)dis[u] + val[i]){
                dis[to[i]] = dis[u] + val[i];
                tmp.w = dis[to[i]];
                tmp.v = to[i];
                q.push(tmp);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);  // 加速cin/cout
    cin>>n>>m>>k;
    cin>>s>>t;

    for(int i = 1;i <= m;i++){
        int u,v,w; 
        cin>>u>>v>>w;
        add(u,v,w);               // 建图
        add(v,u,w);               // 无向图需要加反向边
       for(int j = 1; j <= k; j++){
        add(u + j * n, v + j * n, w);        // 同层付费
        add(v + j * n, u + j * n, w);
        add(u + (j-1) * n, v + j * n, 0);    // 跨层免费（写法更清晰）
        add(v + (j-1) * n, u + j * n, 0);
        }
    }
    dijkstra();
    int ans = inf;
    for(int j = 0;j <= k;j++){
        if(dis[t + j * n] < ans) ans = dis[t + j * n];  
    }
     cout<<ans<<endl;    
}
