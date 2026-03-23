#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
//#define int long long
char a[maxn][maxn];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c,k,ans = 0,found = 0;
    int vis[maxn][maxn][2];
    memset(vis,0,sizeof(vis));
    cin >> r >> c >> k;
    for(int i = 1;i <= r;i++){
        for(int j = 1;j <= c;j++){
            cin >> a[i][j];
            if(a[i][j] == '.')found++;
        }
    }
    if(k == 1){
        cout<<found;
        return 0;
    }
    for(int i = 1;i <= r;i++){
        for(int j = 1;j <= c;j++){
            if(a[i][j] == '.'){
                vis[i][j][0] = vis[i][j - 1][0] + 1;
                vis[i][j][1] = vis[i - 1][j][1] + 1;
                if(vis[i][j][0] >= k) ans++;
                if(vis[i][j][1] >= k) ans++;
            }
            else if(a[i][j] == '#'){
                vis[i][j][0] = 0;
                vis[i][j][1] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}