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
#define maxn 1010
int a[maxn][maxn];
int f1[maxn][maxn],f2[maxn][maxn],n,x,y,ans1 = 200000000,ans2 = -ans1;

void solve(){
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>a[i][i];
    for(int i = 1;i <= n;i++){
        a[n + i][n + i] = a[i][i];
    }
    for(int i = 2;i <= n;i++){
        for(int j = 1;j <= n + n - i + 1;j++){
            x = j;
            y = i + j - 1;
            for(int k = 1;k < i;k++){
                a[x][y] = a[x][x + k - 1] + a[x + k][y];
                if(f1[x][y] != 0)
                    f1[x][y] = min(f1[x][y],f1[x][x + k - 1] + f1[x + k][y] + a[x][y]);
                else
                    f1[x][y] = f1[x][x + k - 1] + f1[x + k][y] + a[x][y];
                if(f2[x][y] != 0)
                    f2[x][y] = max(f2[x][y],a[x][y] + f2[x][x + k - 1] + f2[x + k][y]);
                else f2[x][y] = a[x][y] + f2[x][x + k - 1] + f2[x + k][y]; 
            }
        }
    }
    for(int i = 1;i <= n - 1;i++){
        ans1 = min(ans1,f1[i][i + n - 1]);
    }
    for(int i = 1;i <= n - 1;i++){
        ans2 = max(ans2,f2[i][i + n - 1]);
    }
    cout<<ans1<<endl<<ans2<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}