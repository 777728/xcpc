#include<iostream>
using namespace std;
#define maxn 500010                    // 最大节点数
const int inf = 2147483647;           // 无穷大（约10^9）
int n,m,s,cnt;                        // n点m边s起点，cnt边计数器
int dis[maxn],h[maxn],to[maxn],val[maxn],nxt[maxn];  // 链式前向星数组
bool vis[maxn];                       // 标记是否已确定最短路

// 链式前向星加边：头插法
void add(int a,int b,int c){
    to[++cnt] = b;     // 第cnt条边指向b
    val[cnt] = c;      // 边权为c
    nxt[cnt] = h[a];   // 下一条边是原h[a]
    h[a] = cnt;        // a的头指针指向新边
}

void dijkstra(){
    for(int i = 1;i <= n;i++) dis[i] = inf;  // 初始化距离为无穷
    dis[s] = 0;                               // 起点距离为0
    dis[0] = inf;                             // 哨兵，方便比较
    
    while(true){
        int u = 0;
        // ❌ 以下for循环内缩进有误，逻辑应拆分：
        for(int i = 1;i <= n;i++){           // 遍历所有点找最小dis
            if(!vis[i] && dis[u] > dis[i])   // 未访问且距离更小
                u = i;                        // 更新候选点
        }                                     // ✅ for应在此结束
        
        if(u == 0) break;                    // 无可达点，退出
        vis[u] = 1;                           // 标记u已确定
        
        for(int i = h[u];i;i = nxt[i]){      // 遍历u的所有出边
            if(dis[to[i]] > (long long)dis[u] + val[i])  // 松弛操作
                dis[to[i]] = dis[u] + val[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);  // 加速cin/cout
    cin>>n>>m>>s;
    for(int i = 1;i <= m;i++){
        int u,v,w; cin>>u>>v>>w;
        add(u,v,w);               // 建图
    }
    dijkstra();
    for(int i = 1;i <= n;i++)
        cout<<dis[i]<<" ";        // ✅ 原题要求空格分隔
}
/*初始: h[1]=0, cnt=0

【加 1→2】(cnt=1)
  to[1]=2, val[1]=3
  nxt[1] = h[1] = 0   ← 新边1的下一条是空
  h[1] = 1            ← 头指针指向边1
  链表: 1 → 0

【加 1→3】(cnt=2)
  to[2]=3, val[2]=5
  nxt[2] = h[1] = 1   ← 新边2的下一条是旧头(边1) ✅关键行
  h[1] = 2            ← 头指针更新为边2
  链表: 2 → 1 → 0

【加 1→4】(cnt=3)
  to[3]=4, val[3]=7
  nxt[3] = h[1] = 2   ← 新边3的下一条是旧头(边2)
  h[1] = 3
  链表: 3 → 2 → 1 → 0
  */