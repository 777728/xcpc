#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long 
//const int maxn = 50;
const int inf = 2e9;
#define mod 998244353
#define maxn 202

int a[110][110],f[110][110][110],n,k,ans = -inf;

signed main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            cin>>a[i][j];    
        }
    }
    for(int j = 1;j <= n;j++){
        f[n][j][0] = a[n][j];
        f[n][j][1] = a[n][j] * 3;
        for(int kk = 2;kk <= k;kk++){
            f[n][j][kk] = -2 * inf;
        }
    }
    for(int i = n - 1;i >= 1;i--){
        for(int j = 1;j <= i;j++){
            for(int kk = 0;kk <= k;kk++){
                f[i][j][kk] = max(f[i + 1][j][kk],f[i + 1][j + 1][kk]) + a[i][j];
                if(kk > 0) f[i][j][kk] = max(f[i][j][kk],max(f[i + 1][j][kk - 1],f[i + 1][j + 1][kk - 1]) + a[i][j] * 3);
            }
        }
    }
    for(int i = 0;i <= k;i++){
        ans = max(ans,f[1][1][i]);
    }
    cout << ans << endl;
}