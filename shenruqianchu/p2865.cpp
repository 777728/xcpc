#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 200010
const int inf = 2147483647;  
       
int head[maxn], cnt0, dis[3][maxn], n, m;

struct edge{
    int nxt, to, dis;
} edge[maxn];

struct node {
    int pos, dis;
    bool operator < (const node& b) const {
        return dis > b.dis;  // 小根堆：dis 小的优先级高
    }
};

priority_queue<node> q;

void add(int a, int b, int c){
    edge[++cnt0].to = b;
    edge[cnt0].dis = c;
    edge[cnt0].nxt = head[a];
    head[a] = cnt0;
}

void dijkstra2(){
    for(int i = 1; i <= n; i++){
        dis[0][i] = inf;
        dis[1][i] = inf;
    }
    dis[0][1] = 0;
    q.push({1, 0});  // ✅ {pos, dis}
    
    while(!q.empty()){
        node cur = q.top(); q.pop();  // ✅ 局部声明
        int u = cur.pos, d = cur.dis;
        if(d > dis[1][u]) continue;   // 剪枝：已超过次短路
        
        for(int i = head[u]; i; i = edge[i].nxt){
            int v = edge[i].to;
            int w = edge[i].dis;
            int nd = d + w;
            
            if(nd < dis[0][v]){
                dis[1][v] = dis[0][v];  // 原最短路→次短路
                dis[0][v] = nd;         // 更新最短路
                q.push({v, dis[0][v]});
                q.push({v, dis[1][v]}); // 旧最短路可能更新其他点
            }
            else if(nd > dis[0][v] && nd < dis[1][v]){
                dis[1][v] = nd;
                q.push({v, dis[1][v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cnt0 = 0;  // ✅ 显式初始化
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra2();
    cout << dis[1][n] << '\n';
    return 0;
}