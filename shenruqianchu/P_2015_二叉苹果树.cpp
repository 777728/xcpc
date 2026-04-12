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
const int maxn = 110;

int dp[maxn][110];
int son[maxn][2],siz[maxn];
int val[maxn][2];
int n,q;

void gma(int &x,int y){
    x < y? x = y : 0;
}

void dfs(int u){
    int x = son[u][0],y = son[u][1];
    if(x == 0&& y == 0) return;
    dfs(x); dfs(y);
    siz[u] = siz[x] + siz[y] + 2;
    for(int i = -1;i <= siz[x];i++){
        for(int j = -1;j <= siz[y];j++){
            int vl = (i == -1) ? 0 : dp[x][i] + val[u][0];
            int vr = (j == -1) ? 0 : dp[y][j] + val[u][1];
            gma(dp[u][i+j+2],vl+vr);
        }
    }
}
void solve(){
    cin>>n>>q;
    for(int i = 1;i < n;i++){
        int x;
        cin>>x;
        int b = son[x][0] > 0;
        cin>>son[x][b]>>val[x][b];
    }
    dfs(1);
    cout<<dp[1][q]<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}