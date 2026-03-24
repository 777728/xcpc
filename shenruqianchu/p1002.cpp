#include <iostream>
using namespace std;
#define int long long
#define maxn 22
int d[9][2] = {{0,0},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int f[maxn][maxn] = {0};
int ctl[maxn][maxn] = {0};

signed main(){
    int n,m,hx,hy;
    cin>>n>>m>>hx>>hy;
    for(int i = 0;i < 9;++i){
        int tempx = hx + d[i][0];
        int tempy = hy + d[i][1];
        if(tempx >= 0&&tempy >= 0&&tempx <= n&&tempy <= m){
            ctl[tempx][tempy] = 1;
        }
    }
    f[0][0] = 1 - ctl[0][0];
    for(int i = 0;i <= n;++i){
        for(int j = 0;j <= m;++j){
            if(ctl[i][j])continue;
            if(i != 0) f[i][j] += f[i-1][j];
            if(j != 0) f[i][j] += f[i][j - 1];
        }
    }
    cout<<f[n][m];
}