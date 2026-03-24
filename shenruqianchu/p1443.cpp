#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
queue<pair<int,int>>q;
#define maxn 405
int f[maxn][maxn];//最少的步数
bool vis[maxn][maxn];
int dx[8] = {-2,-2,-1,1,2,2,-1,1};
int dy[8] = {1,-1,2,2,1,-1,-2,-2};
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    memset(f,127,sizeof(f));
    f[x][y] = 0,vis[x][y] = true;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
       for(int i = 0;i < 8;++i){
           int tmpx = nowx + dx[i];
           int tmpy = nowy + dy[i];
           if(tmpx>0&&tmpx<=n&&tmpy>0&&tmpy<=m&&!vis[tmpx][tmpy]){
               f[tmpx][tmpy] = f[nowx][nowy] + 1;
               q.push(make_pair(tmpx,tmpy));
               vis[tmpx][tmpy] = 1;
           }
       } 
    }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(f[i][j] > 10000)cout<<-1<<" ";
                else cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }
}