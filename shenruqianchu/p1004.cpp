#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
//const int maxn = 50;
const int inf = 2e9;
#define mod 998244353
const int maxn = 202;

int a[maxn][maxn] = {0},dp[maxn * 2][maxn][maxn],n,m;

signed main(){
    ios::sync_with_stdio(false);
    cin >> n;
    int i ,j, z;
    while(cin>> i >> j >> z){
        if(i == 0 && j == 0 && z == 0) break;
        a[i][j] = z;
    }
    for(int s = 2;s <= 2 * n;s++){
      for(int i = max(s - n,1);i <= min(n , s - 1);i++){
        for(int k = max(s - n,1);k <= min(n, s - 1);k++){
            dp[s][i][k] = dp[s - 1][i][k];
            dp[s][i][k] = max(dp[s][i][k],dp[s - 1][i - 1][k - 1]);
            dp[s][i][k] = max(dp[s][i][k],dp[s - 1][i][k - 1]);
            dp[s][i][k] = max(dp[s][i][k],dp[s - 1][i - 1][k]);
            if(i != k) dp[s][i][k] += a[i][s - i] + a[k][s - k];
            else dp[s][i][k] += a[i][s - i];
        }
      }  
    }
    cout << dp[2 * n][n][n] << endl;
}