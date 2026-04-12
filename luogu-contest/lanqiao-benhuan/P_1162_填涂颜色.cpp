#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 35
int n;
int a[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x,int y){
    if(x < 0 || x > n + 1 || y < 0 || y > n + 1 || a[x][y] == 1)
        return;
    a[x][y] = 2;
    vis[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int tmpx = x + dx[i],tmpy = y + dy[i];
        if(!vis[tmpx][tmpy]) dfs(tmpx,tmpy);
    }
}
void solve(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin>>a[i][j];
        }
    }
    vis[0][0] = 1;
    dfs(0,0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout<<2 - a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}