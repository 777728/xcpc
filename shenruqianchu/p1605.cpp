#include <iostream>
#include <cstring>
using namespace std;
#define maxn 10
int mi[maxn][maxn];  // 障碍物标记
bool vis[maxn][maxn]; // 访问标记
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;
int n, m, t;
int sx, sy, fx, fy;  // 起点和终点坐标

void dfs(int x, int y) {
    // 到达终点，方案数+1
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    
    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 检查是否在迷宫范围内
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        
        // 检查是否可走（没有障碍且未访问过）
        if (!vis[nx][ny] && mi[nx][ny] != -1) {
            vis[nx][ny] = true;  // 标记访问
            dfs(nx, ny);         // 递归探索
            vis[nx][ny] = false; // 回溯，撤销标记
        }
    }
}

int main() {
    cin >> n >> m >> t;
    
    // 初始化
    memset(vis, 0, sizeof(vis));
    memset(mi, 0, sizeof(mi));
    
    cin >> sx >> sy >> fx >> fy;
    
    // 标记障碍
    for (int i = 1; i <= t; ++i) {
        int deadx, deady;
        cin >> deadx >> deady;
        mi[deadx][deady] = -1;
    }
    
    // 从起点开始DFS
    vis[sx][sy] = true;  // 标记起点已访问
    dfs(sx, sy);
    
    cout << ans << endl;
    
    return 0;
}