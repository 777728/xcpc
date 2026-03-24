#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 310
#define int long long
int loc[maxn][maxn];//这个位置最早的流行时刻
int ans[maxn][maxn];
int m;
int shi[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
int ANS = 1e9;
struct star{
    int x;
    int y;
    int t;
}liu[50005]; // 1. 数组大小不足，M<=50000
struct niu{
    int x;
    int y;
};
signed main(){
    cin>>m;
    memset(ans,-1,sizeof(ans));
    memset(loc,127,sizeof(loc));
    for(int i = 0;i < m;++i){
        cin>>liu[i].x>>liu[i].y>>liu[i].t;
        for(int j = 0;j < 5;++j){
            int tempx = liu[i].x + shi[j][0];
            int tempy = liu[i].y + shi[j][1];
            if(tempx >= 0 && tempy >= 0) // 2. 防止负坐标越界
                loc[tempx][tempy] = min(liu[i].t,loc[tempx][tempy]);    
        }
    }
    // 3. 起点若不可达直接结束
    if(loc[0][0] == 0) { cout << -1; return 0; } 

    queue<niu>q;
    q.push((niu){0,0});
    ans[0][0] = 0;
    while(!q.empty()){
        niu u = q.front();
        int ux = u.x;
        int uy = u.y;
        q.pop();
        for(int k = 1;k < 5;k++){
            int x = ux + shi[k][0];
            int y = uy + shi[k][1];
            // 4. 增加上界检查，修正判断的 loc 坐标为目标点 (x,y)
            if(x<0||y<0||x>=maxn||y>=maxn||ans[x][y] != -1||ans[ux][uy] + 1 >= loc[x][y]) continue;
            ans[x][y] = ans[ux][uy] + 1;
            q.push((niu){x,y});
        }
    }
    for(int i = 0;i < maxn;++i){ // 5. 循环边界修正
        for(int j = 0;j < maxn;++j){
            // 6. memset 127 后 int 值为 0x7f7f7f7f，不等于 127，且安全区时间应大于最大流星时间 1000
            if(loc[i][j] > 1000 && ans[i][j] != -1){
                ANS = min(ANS,ans[i][j]);
            }
        }
    }
    if(ANS==1e9)cout<<"-1";
    else
        cout<<ANS;
    
    return 0;
}