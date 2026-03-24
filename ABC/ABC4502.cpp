#include<bits/stdc++.h> // 头文件
using namespace std; // 命名空间
#define maxn 1010 // 宏定义
//#define int long long // 防溢出
char a[maxn][maxn]; // 数组
int vis[maxn][maxn]; // 访问数组
int dx[4] = {0,0,1,-1}; // 方向数组
int dy[4] = {1,-1,0,0};
int main(){ //   主函数
    ios::sync_with_stdio(0); cin.tie(0);
    int h,w;
    int ans = 0; // 答案
    cin>>h>>w;
    memset(vis,0,sizeof(vis)); // 初始化访问数组
    for(int i = 1;i <= h;i++){ // 输入数组
        for(int j = 1;j <= w;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i <= h;i++){ // 输出数组
        for(int j = 1;j <= w;j++){
            if(a[i][j] == '.' && !vis[i][j]){ // 如果是*且未访问
                bool flag = 0; // 标志
                queue<pair<int,int>> q; // 队列
                q.push({i,j}); // 入队
                vis[i][j] = 1; // 标记访问
                while(!q.empty()){ // BFS
                    auto t = q.front(); // 取队头
                    q.pop(); // 出队
                    if(t.first == 1 || t.first == h || t.second == 1 || t.second == w){ // 如果在边界上
                        flag = 1; // 不是孤立的
                    }
                    for(int k = 0;k < 4;k++){ // 遍历四个
                        int x = t.first + dx[k];
                        int y = t.second + dy[k];
                        if(x >= 1 && x <= h && y >= 1 && y <= w&&a[x][y] == '.'&&vis[x][y] == 0){ // 如果在范围内
                            q.push({x,y}); // 入队
                            vis[x][y] = 1; // 标记访问
                        }
                    }
                }
                if(flag == 0)ans++;
            }
        }
    }
    cout<<ans<<endl;
}