#include<iostream>
#include<cstring>
#define maxn 500010
#define ll long long
using namespace std;
int n,m,a[110][110],f[110][110];
int dfs(int x,int y){
    if(x > n || y > m || x < 1 || y < 1) return 0;
    if(f[x][y] != -1) return f[x][y];
    int ans = 0;
    if(a[x][y] > a[x][y + 1])ans = max(ans,dfs(x,y + 1));
    if(a[x][y] > a[x + 1][y])ans = max(ans,dfs(x + 1,y));
    if(a[x][y] > a[x][y - 1])ans = max(ans,dfs(x,y - 1));
    if(a[x][y] > a[x - 1][y])ans = max(ans,dfs(x - 1,y));
    f[x][y] = ans + 1;
    return f[x][y];
}
int main(){
    cin>>n>>m;
    memset(f,-1,sizeof(f));
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j++){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ans = max(ans,dfs(i,j));
        }
    }
    cout<<ans<<endl;
}