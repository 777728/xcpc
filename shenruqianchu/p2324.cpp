#include <iostream>
#include <cstring>
using namespace std;
int T;
char g[6][6], init[6][6]; // 保存初始状态
char target[6][6] = {
    {' ',' ',' ',' ',' ',' '},
    {' ','1','1','1','1','1'},
    {' ','0','1','1','1','1'},
    {' ','0','0','*','1','1'},
    {' ','0','0','0','0','1'},
    {' ','0','0','0','0','0'}
};
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

int heuristic() {
    int cnt = 0;
    for(int i=1; i<=5; i++)
        for(int j=1; j<=5; j++)
            if(g[i][j] != target[i][j]) cnt++;
    return cnt;
}

bool dfs(int x, int y, int step, int limit) {
    int h = heuristic();
    if(h == 0) return true;
    if(step == limit) return false;
    // 放宽剪枝条件：h-1 因为空位移动可能同时修正 2 个格子
    if(step + h - 1 > limit) return false;

    for(int i=0; i<8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx>=1 && nx<=5 && ny>=1 && ny<=5) {
            swap(g[x][y], g[nx][ny]);
            if(dfs(nx, ny, step+1, limit)) return true;
            swap(g[x][y], g[nx][ny]);
        }
    }
    return false;
}

int main() {
    cin >> T;
    while(T--) {
        int sx, sy;
        for(int i=1; i<=5; i++)
            for(int j=1; j<=5; j++) {
                cin >> g[i][j];
                init[i][j] = g[i][j]; // 保存初始状态
                if(g[i][j] == '*') sx = i, sy = j;
            }
        
        int ans = -1;
        for(int i=0; i<=15; i++) {
            // 每次迭代从初始状态重新开始
            memcpy(g, init, sizeof(g));
            if(dfs(sx, sy, 0, i)) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}