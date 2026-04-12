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

int n,m;
int dis[55][55];
bool g[55][55],f[35][55][55];

void dp(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(g[i][j] != 0) f[0][i][j] = 1;
        }
    }
    for(int i = 1;i <= 30;i++){
        for(int k = 1;k <= n;k++){
            for(int u = 1;u <= n;u++){
                for(int v = 1;v <= n;v++){
                    f[i][u][v] |= f[i - 1][u][k] & f[i - 1][k][v];
                }
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int x,y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    dp();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j) dis[i][j] = 1e9;
        }
    }
    for(int i = 0;i <= 30;i++){
        for(int u = 1;u <= n;u++){
            for(int v = 1;v <= n;v++){
                if(f[i][u][v]) dis[u][v] = min(dis[u][v],1);
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(k != i && k != j && i != j)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    cout<<dis[1][n]<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}