#include<iostream>
using namespace std;
char biao[11][11];
int vis[11][11][4][11][11][4]; // 记录农夫和牛的状态是否出现过
int dx[4] = {-1,0,1,0}; // 修改方向顺序：0上 1右 2下 3左
int dy[4] = {0,1,0,-1};
struct animal{
    int x;
    int y;
    int dir;
}farmer,cow;

int main(){
    // 读入地图
    for(int i = 1;i <= 10;i++){
        for(int j = 1;j <= 10;j++){
            cin>>biao[i][j];
            if(biao[i][j] == 'C'){
                cow.x = i;
                cow.y = j;
                cow.dir = 0; // 初始方向向北
            }
            else if(biao[i][j] == 'F'){
                farmer.x = i;
                farmer.y = j;
                farmer.dir = 0; // 初始方向向北
            }
        }
    }
    
    int t = 0;
    bool found = false;
    
    while(true){
        // 检查是否相遇
        if(farmer.x == cow.x && farmer.y == cow.y){
            found = true;
            break;
        }
        
        // 检查是否陷入循环
        if(vis[farmer.x][farmer.y][farmer.dir][cow.x][cow.y][cow.dir]){
            break;
        }
        
        // 记录当前状态
        vis[farmer.x][farmer.y][farmer.dir][cow.x][cow.y][cow.dir] = 1;
        
        // 农夫移动
        int fnx = farmer.x + dx[farmer.dir];
        int fny = farmer.y + dy[farmer.dir];
        if(fnx >= 1 && fnx <= 10 && fny >= 1 && fny <= 10 && biao[fnx][fny] != '*'){
            farmer.x = fnx;
            farmer.y = fny;
        } else {
            farmer.dir = (farmer.dir + 1) % 4;
        }
        
        // 牛移动
        int cnx = cow.x + dx[cow.dir];
        int cny = cow.y + dy[cow.dir];
        if(cnx >= 1 && cnx <= 10 && cny >= 1 && cny <= 10 && biao[cnx][cny] != '*'){
            cow.x = cnx;
            cow.y = cny;
        } else {
            cow.dir = (cow.dir + 1) % 4;
        }
        
        t++;
        
        // 防止无限循环（但已经通过vis数组检查）
        if(t > 1000000){
            break;
        }
    }
    
    if(found) cout << t;
    else cout << 0;
    
    return 0;
}